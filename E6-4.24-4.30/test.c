#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int, int);
int max(int, int);
#define N 1010
#define INF 1e9

int n, m;
int f[N][N];
//  f[i][j]表示共i层楼j个鸡蛋时最少要试几次保证能找到临界点

int main()
{
    int i, j, k;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        f[i][1] = i;
        for (j = 2; j <= m; j++)
        {
            //  要求最小值时，先反向赋一个很大的值
            f[i][j] = INF;
            //  遍历鸡蛋扔在的k层的情况
            for (k = 1; k <= i; k++)
            /*  
                    设临界值为t
                    f[k - 1][j - 1]为鸡蛋碎了，t在[1, k]这个区间中，共k层，剩余j - 1个鸡蛋
                    f[i - k][j]为鸡蛋未碎，t在[k + 1, i]这个区间中，共i - k层，剩余j个鸡蛋
                    在两种情况中取较大值（考虑最坏情况）加上本次，更新f[i][j]
                */
            {
                f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d\n", f[i][j]);
        }
    }
    return 0;
}

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    else
    {
        return a;
    }
}