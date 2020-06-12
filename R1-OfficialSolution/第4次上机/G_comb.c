/* 提供一种用组合数来解决此问题的做法，此方法的时间复杂度远远高于正解(即运算效率低于正解)，仅供参考 */
/* 本方法按照1的个数和[2,3]的个数分类，cnt1代表1的个数，cnt2代表"相邻的一对2和3"的个数，这里将一对相邻的[2,3]当做整体。
 * 对于某种特定的情况，即特定的cnt1和cnt2(cnt1 + 2 * cnt2 = n这个等式总是成立的)，其方法数可以用如下的方法求得：
 * 首先将这些1和[2,3]安排相对顺序，相当于一共cnt1+cnt2个位置，选择其中的cnt1个位置放1或者选择其中cnt2个位置放[2,3]，
 * 这一步的方法数可以由组合数C cnt1+cnt2 cnt1或者C cnt1+cnt2 cnt2计算出来。
 * 接下来，对于每一个[2,3]整体，其内部是有A 2 2 = 2种摆放方法，所以对于cnt2个[2,3]其内部的顺序共有pow(2, cnt2)种。
 * 将以上两个结果相乘，即C(cnt1+cnt2, cnt1) * pow(2, cnt2)即可得到在特定的1的个数下的方法种数。
 * 将不同个数的1对应的方法数相加即可得到答案。
 * 
 * 处理的过程中注意一些问题：
 * 1. 由于本题要多次计算组合数，可能导致大量重复的递归，所以采取记忆化的处理。
 *    所谓记忆化，即利用好求过的答案。对于特定的m,n，如果其组合数在先前的递归中已经被求过了，则直接返回结果，无需再次递归计算。
 *    并且通过递归计算好的comb_num(m,n)也要在返回结果的同时存入数组。
 *    在下方的示例代码中，例如return (comb[m][n] = m)的含义为：将m存入数组，同时作为返回值，其他返回赋值表达式的return同理。
 * 2. 对于结果较大需要取模的题目，一定要一边运算一边取模，千万别等到最后。及时取模好比及时抑制结果突然变大的趋势，防止溢出。
 * 3. 计算2的次幂时，不要用pow(2,cnt2)计算，因为pow算出来是浮点数，这个数有可能非常非常大，而且在数量级过大时浮点数会丧失精度。
 *    另外浮点数可能不能取模。
 *    所以这里我的做法是直接抄来L题的快速幂取余的代码，注意有一个小细节就是把PowMod里边的a改成long long型，
 *    否则在乘法过程中可能会溢出。(不信的话可以用它来算算2的32次方对MOD取余，如果不加long long和1LL可能得到0或者负数)
 */
#include <stdio.h>
#define MOD 1000007
#define MAXN 255
int comb[MAXN][MAXN];
typedef long long ll;
int comb_num(int m, int n)
{
    if (comb[m][n]) return comb[m][n];
    if (m < n) return (comb[m][n] = 0);
    if (n == 1) return (comb[m][n] = m);
    if (n == m || n == 0) return (comb[m][n] = 1);
    return (comb[m][n] = (comb_num(m - 1, n) % MOD + comb_num(m - 1, n - 1) % MOD) % MOD);
}
int PowMod(ll  a, int t, int p)
{
    ll ret = 1;
    while (t) {
        if (t & 1) ret = 1LL * ret * a % p;
        a = 1LL * a * a % p;
        t >>= 1;
    }
    return ret;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ans = 0;
        for (int cnt1 = n; cnt1 >= 0; cnt1 -= 2)
        {
            int cnt2 = (n - cnt1) >> 1;
            ll dx = (1LL * comb_num(cnt1 + cnt2, cnt1) * PowMod(2, cnt2, MOD)) % MOD;
            ans = (ans + dx) % MOD;
        }
        printf("%d\n", ans);
    }
}
