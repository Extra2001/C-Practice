#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int TrimEndR(char *base);

int yes[200010];

int cmp(const void *a, const void *b)
{
    int *e = (int *)a, *f = (int *)b;
    return *f - *e;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        // for (int i = 0; i < n; i++)
        //     scanf("%d", &a[i]);
        // for (int i = 0; i < m; i++)
        //     scanf("%d", &b[i]);
        // for (int i = n - 1, j = 0, cnt = 0, l = 0; l < n + m; l++)
        // {
        //     if (i >= 0 && j < m)
        //     {
        //         if (a[i] < b[j])
        //             yes[cnt++] = b[j++];
        //         else
        //             yes[cnt++] = a[i--];
        //     }
        //     else if (i >= 0)
        //         yes[cnt++] = a[i--];
        //     else if (j < m)
        //         yes[cnt++] = b[j++];
        // }
        for (int i = 0; i < n + m; i++)
            scanf("%d", &yes[i]);
        qsort(yes, n + m, sizeof(yes[0]), cmp);
        for (int i = 0; i < k; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            int *p = (int *)bsearch(&tmp, yes, n + m, sizeof(yes[0]), cmp);
            if (p != NULL)
            {
                while (*p == tmp)
                    p--;
                p++;
                printf("%lld ", p - yes + 1);
            }
            else
                printf("-1 ");
        }
        putchar('\n');
    }
    // fclose(stdin);
}