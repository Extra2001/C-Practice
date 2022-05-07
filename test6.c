#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long a[50005];
int main()
{
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    int v, n;
    scanf("%d%d", &v, &n);
    a[1] = v;
    int i, j, k, tmp;
    j = 2;
    long long sum = 0;
    sum += v;
    int min1, min2, max1, max2;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if (tmp == 3)
        {
            a[j] = v;
            j++;
            sum += v;
            printf("Day %d: %lld\n", i, sum);
        }
        else if (tmp == 1)
        {
            min1 = a[1];
            min2 = 1;
            for (k = 2; k < j; k++)
            {
                if (min1 > a[k])
                {
                    min1 = a[k];
                    min2 = k;
                }
            }
            if (2 * a[min2] > v)
            {
                a[min2] = v;
                sum += v - min1;
            }
            else
            {
                a[min2] = min1 * 2;
                sum += min1;
            }
            printf("Day %d: %lld\n", i, sum);
        }
        else if (tmp == 2)
        {
            if (sum == 0)
            {
                printf("Day %d: Such beautiful flowers, what a pity!\n", i);
            }
            else
            {
                max1 = a[1];
                max2 = 1;
                for (k = 2; k < j; k++)
                {
                    if (max1 < a[k])
                    {
                        max1 = a[k];
                        max2 = k;
                    }
                }
                a[max2]--;
                sum--;
                printf("Day %d: %lld\n", i, sum);
            }
        }
    }
    return 0;
}