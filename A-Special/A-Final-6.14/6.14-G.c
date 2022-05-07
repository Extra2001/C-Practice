#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

typedef long long LL;

double area(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3)
{
    double x1 = sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2) + (c1 - c2) * (c1 - c2));
    double x2 = sqrt((a3 - a2) * (a3 - a2) + (b3 - b2) * (b3 - b2) + (c3 - c2) * (c3 - c2));
    double x3 = sqrt((a3 - a1) * (a3 - a1) + (b3 - b1) * (b3 - b1) + (c3 - c1) * (c3 - c1));
    double p = (double)(x1 + x2 + x3) / 2.0;
    return sqrt(p * (p - x1) * (p - x2) * (p - x3));
}

double a[105], b[105], c[105];
double ar[1000000];

int cmp(const void *a, const void *b)
{
    double *e = (double *)a, *f = (double *)b;
    if (*e == *f)
    {
        return 0;
    }
    if (*e - *f < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    IN1(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                double tmp = fabs(area(a[i], b[i], c[i], a[j], b[j], c[j], a[k], b[k], c[k]));
                if (tmp > 1e-6)
                {
                    ar[cnt++] = tmp;
                }
            }
        }
    }
    qsort(ar, cnt, sizeof(ar[0]), cmp);
    for (int i = 0; i < cnt; i++)
    {
        printf("%lf\n", ar[i]);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}