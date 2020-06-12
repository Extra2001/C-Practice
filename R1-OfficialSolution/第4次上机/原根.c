#include <stdio.h>

int Phi(int x)
{
    int ret = x;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ret = ret / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        ret = ret / x * (x - 1);
    return ret;
}

int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}

int PowMod(int bas, int t, int mod)
{
    int ret = 1;
    while (t)
    {
        if (t & 1)
            ret = ret * bas % mod;
        bas = bas * bas % mod;
        t >>= 1;
    }
    return ret;
}

int main()
{
    int p, a, ph, q, d, haveAns, i;
    scanf("%d", &q);
    for (i = 0; i < q; ++i)
    {
        scanf("%d", &p);
        haveAns = 0;    //初始化一定不要忘记 
        ph = Phi(p);    // 加速。 
        for (a = 1; a <= p; ++a)
        {
            if (GCD(a, p) == 1)
            {
                for (d = 1; d <= ph; ++d)
                {
                    if (PowMod(a, d, p) == 1)
                    {
                        if (d == ph)
                        {
                            printf("%d ", a);
                            haveAns = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        if (haveAns == 0)
        {
            printf("-1");
        }
        printf("\n");   // 多组数据输出的换行一定不要忘了 
    }
}
