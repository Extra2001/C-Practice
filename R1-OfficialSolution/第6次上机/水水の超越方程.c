#include <stdio.h>
#include <math.h>

double a, b, c, e = 2.71828182845;
double esp = 1e-7;

double f(double x)
{
    return a * x * log(x) - b * exp(-pow(x - 1 / e, 4)) + c;
}

double g(double x)
{
}

int main()
{
    double m, n, L, R, mid;
    int plus;
    while (scanf("%lf %lf %lf", &a, &b, &c) > 0)
    {
        // printf("%f", f(1.280324));
        m = f(1 / e);
        n = f(1e6);
        plus = n > m;
        if (m * n > 0)
        {
            printf("No solution.\n");
        }
        else
        {
            L = 1 / e;
            R = 1e6;
            while (R - L > esp)
            {
                mid = (L + R) / 2.0;
                if (plus)
                {
                    if (f(mid) > 0)
                    {
                        R = mid;
                    }
                    else
                    {
                        L = mid;
                    }
                }
                else
                {
                    if (f(mid) > 0)
                    {
                        L = mid;
                    }
                    else
                    {
                        R = mid;
                    }
                }
            }
            printf("%0.7f\n", mid);
        }
    }
}