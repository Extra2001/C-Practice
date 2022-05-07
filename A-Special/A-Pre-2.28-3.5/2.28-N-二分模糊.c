#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

unsigned long c[4000000];

int TrimEndR(char *base);

int a[3000], b[3000];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

unsigned long *myBSearch(unsigned long *key, unsigned long *base, int count)
{
    int left = 0, right = count - 1, mid;
    while (1)
    {
        mid = (left + right) / 2;
        if (base[mid] == *key)
        {
            while (base[mid] == *key)
                mid++;
            return base + mid - 1;
        }
        else if (right - left >= 4)
        {
            if (base[mid] > *key)
                left = mid;
            else
                right = mid;
        }
        else
        {
            while (base[mid] > *key && mid < count)
                mid++;
            while (base[mid] < *key && mid >= 0)
                mid--;
            if (mid < 0 || mid >= count)
                return NULL;
            return base + mid;
        }
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n, i, j, p, tmp;
    unsigned long t;
    scanf("%d%d\n", &n, &m);
    p = n * n;
    unsigned long a[n], o[m];
    for (i = 0; i < n; i++)
    {
        scanf("%lu", &a[i]);
    }
    tmp = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%lu", &t);
        for (j = 0; j < n; j++)
        {
            c[tmp + j] = a[j] + t;
        }
        tmp += n;
    }
    int cnt = n * n;
    qsort(c, cnt, sizeof(c[0]), cmp);
    unsigned long *find;
    for (i = 0; i < m; i++)
    {
        scanf("%lu", &t);
        find = myBSearch(&t, c, cnt);
        if (find)
        {
            printf("%d\n", find - c + 1);
        }
        else
        {
            printf("0\n");
        }
    }

    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}