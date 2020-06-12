#include <stdio.h>

int main()
{
    int q;
    int i, j, m, n, t,k;
    int a[1005] = {0}, L, R;
    scanf("%d", &q);
    for (j = 0; j < q; j++)
    {
        scanf("%d %d", &n, &m);

        for (i = 1; i <= n; i++)
        {
            a[i] = i;
        }

        for (i = 0; i < m; ++i)
        {
            scanf("%d %d", &L, &R);
            for (k = L; 2 * k < (R + L); k++) //[1,3]1->3 [1,4]
            {
                t = a[k];
                a[k] = a[R + L - k];
                a[R + L - k] = t;
            }
        }

        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        putchar('\n');
    }
}