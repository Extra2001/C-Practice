#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

double a[300];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m;
    double sum = 0.0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%lf", &a[i]);
        sum += a[i];
    }
    double ave = sum / (double)m;
    double su = 0.0;
    for (int i = 0; i < m; i++)
    {
        su += (a[i] - ave) * (a[i] - ave);
    }
    su /= m;
    su = sqrt(su);
    double tmp;
    printf("%.2lf\n%.2lf\n", ave, su);
    for (int i = 0; i < m; i++)
    {
        tmp = (a[i] - ave);
        if (fabs(tmp) > su)
        {
            printf("%.2lf\n", a[i]);
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