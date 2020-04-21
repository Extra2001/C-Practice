#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h1, l1, h2, l2, h3, l3, i = 0, j = 0, k = 0, s = 0;
    scanf("%d %d %d %d %d %d", &h1, &l1, &h2, &l2, &h3, &l3);
    long long int a[h1][l1], b[h2][l2], c[h3][l3], d[h1][l2], e[h1][l3];
    while (j < l1)
    {
        scanf("%lld", &a[i][j]);
        j++;
        if (j == l1)
        {
            j = 0;
            i++;
            if (i == h1)
                j = l1;
        }
    }
    i = j = 0;
    while (j < l2)
    {
        scanf("%lld", &b[i][j]);
        j++;
        if (j == l2)
        {
            j = 0;
            i++;
            if (i == h2)
                j = l2;
        }
    }
    i = j = 0;
    while (j < l3)
    {
        scanf("%lld", &c[i][j]);
        j++;
        if (j == l3)
        {
            j = 0;
            i++;
            if (i == h3)
                j = l3;
        }
    }
    i = j = 0;
    while (i < h1)
    {
        while (j < l2)
        {
            while (k < l1)
            {
                s += a[i][k] * b[k][j];
                k++;
            }
            d[i][j] = s;
            s = 0;
            j++;
            k = 0;
        }
        j = 0;
        i++;
    }
    i = 0;
    while (i < h1)
    {
        while (j < l3)
        {
            while (k < h3)
            {
                s += d[i][k] * c[k][j];
                k++;
            }
            e[i][j] = s;
            s = 0;
            j++;
            k = 0;
        }
        j = 0;
        i++;
    }
    i = 0;
    while (i < h1)
    {
        while (j < l3)
        {
            printf("%lld ", e[i][j]);
            j++;
            if (j == l3)
                printf("\n");
        }
        i++;
        j = 0;
    }
    return 0;
}
