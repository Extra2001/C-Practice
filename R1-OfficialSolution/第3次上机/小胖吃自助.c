#include <stdio.h>

long long a[200];
long long SUM[200];

int main()
{
    int n, i, j, k, L, R;
    long long tmpSum, ans = -1;

    while (scanf("%d", &n) > 0)
    {
        ans = -1;   // ans 初始化
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }

        // for (i = 0; i < n; i++)
        // {
        //     for (j = i; j < n; j++)
        //     {
        //         tmpSum = 0;    // 每次求和之前，重新置0
        //         for (k = i; k <= j; k++)
        //         {
        //             tmpSum += a[k];
        //         }
        //         if (tmpSum < 0)
        //         {
        //             continue;
        //         }

        //         if (tmpSum > ans)
        //         {
        //             ans = tmpSum;
        //             L = i;
        //             R = j;
        //         }
        //         else if (tmpSum == ans)
        //         {
        //             if ((R - L) < (j - i))
        //             {
        //                 L = i;
        //                 R = j;
        //             }
        //         }
        //     }
        // }

// 1 2 3 4 5 6
// 1 3 6 10 15 21


        SUM[0] = a[0];
        for (i = 1; i < n; i++)
        {
            SUM[i] = SUM[i - 1] + a[i];
        }

        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                if (i - 1 < 0)
                {
                    tmpSum = SUM[j];
                }
                else
                {
                    tmpSum = SUM[j] - SUM[i - 1];
                }

                if (tmpSum < 0)
                {
                    continue;
                }

                if (tmpSum > ans)
                {
                    ans = tmpSum;
                    L = i;
                    R = j;
                }
                else if (tmpSum == ans)
                {
                    if ((R - L) < (j - i))
                    {
                        L = i;
                        R = j;
                    }
                }
            }
        }

        if (ans < 0)
        {
            printf("I'm hungry!\n");
        }
        else
        {  // 输出long long 用lld
            printf("%lld %d %d\n", ans, L + 1, R + 1);
        }
    }
}