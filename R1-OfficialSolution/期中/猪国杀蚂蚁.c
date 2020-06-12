#include <stdio.h>

#pragma GCC optimize(3)

int a[100005];

int main()
{
    int m, n, b,i;

    while (scanf("%d %d", &n, &m) > 0)
    {
        for (i = 1; i <= 100004; i++)
        {
            a[i] = 0;
        }
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &b);
            a[b] += 1;
        }

        for (i = 1; i <= m; i++)
        {
            scanf("%d", &b);
            a[b] += 1;
        }

        for (i = 1; i <= 100004; i++)
        {
            if (a[i] == 1)
            {
                printf("%d ", i);
            }
        }

        printf("\n");
    }
}