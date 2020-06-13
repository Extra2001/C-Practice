#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

double a, b, c;

#define EPSILON 1e-8
#define E 2.71828182845

double f(double x)
{
    return a * x * log(x) - b * exp(-pow((x - 1.0 / E), 4)) + c;
}

double solve(double (*func)(double), double left, double right, int asc)
{
    double mid, tmp;
    while (right - left >= EPSILON)
    {
        mid = (right + left) / 2;
        tmp = func(mid);
        if (fabs(tmp) < EPSILON)
            return mid;
        else if (asc * tmp > 0)
            right = mid;
        else
            left = mid;
    }
    return mid;
}

int main()
{

    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    while (~scanf("%lf%lf%lf", &a, &b, &c))
    {
        int isasc = -1;
        if (a > 0 || b > 0)
        {
            isasc = 1;
        }
        double res = 0.0;
        double left = 1.0 / E, right = 1e6;
        if ((f(left) * f(right)) > 0)
        {
            printf("No solution.\n");
            continue;
        }
        res = solve(f, left, right, isasc);
        printf("%lf\n", res);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}