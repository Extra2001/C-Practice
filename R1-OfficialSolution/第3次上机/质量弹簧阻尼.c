#include <stdio.h>

int main()
{
    // 全用double，float精度不够
    double h = 1e-6;
    double m, b, k;
    double x, t, x_, z = 0.0;
    int n, i;
    scanf("%lf %lf %lf", &m, &b, &k);
    scanf("%lf %lf", &x, &t);
    n = (int)(t / h);
    for (i = 0; i < n; ++i)
    {
        x_=x;  //装上一步的x
        x = x + h * z;
        z = z - h / m * (b * z + k * x_);
    }
    printf("%.8f", x);
}