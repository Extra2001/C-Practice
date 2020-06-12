#include <stdio.h>
#include <stdlib.h>

int m[500005][2] = {0};
int n;

int cmp(const void *a, const void *b)
{
    int *m = (int *)a;
    int *n = (int *)b;
    if (*(m + 1) > *(n + 1))
    {
        return 1;
    }
    else if (*(m + 1) < *(n + 1))
    {
        return -1;
    }
    else
    {
        return *m - *n;
    }
}

int main()
{
    int i, j, k, haveANs = 0;
    double mid = -10086.0, midTmp;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d %d", &m[i][0], &m[i][1]);
    }

    qsort(m, n, sizeof(m[0]), cmp);

    for (i = 0; i < n;)
    {
        // printf("aa%d\n", i);
        j = i;
        k = i;
        while (m[j][1] == m[i][1] && j <= n)
        {
            j++;
        }
        i = j;
        j--;
        if (haveANs == 0)
        {
            mid = (double)m[k][0] + (double)m[j][0];
            mid /= 2;
            haveANs=1;
        }
        while (k <= j)
        {
            // printf("aa%f %f\n",mid,);
            midTmp = ((double)m[k][0] + (double)m[j][0]) / 2;
            if (midTmp != mid)
            {
                printf("Not a symmetric figure.");
                return 0;
            }
            k++;
            j--;
        }
    }

    printf("x = %0.1f", mid);
    return 0;
}