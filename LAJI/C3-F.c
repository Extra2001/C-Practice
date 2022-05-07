#include <math.h>
#include <stdio.h>

int main()
{
    double s, m, n, t;
    scanf("%lf%lf%lf%lf", &s, &m, &n, &t);
    double tmp1, tmp2, tmp3, tmp4;
    tmp1 = pow((1 + m / 100.0), t);
    tmp2 = pow((1 + n / 100.0), t * 4.0);
    tmp3 = s * tmp1;
    tmp4 = s * tmp2;
    if (fabs(tmp1 - tmp2) < 1e-8)
    {
        printf("%.2lf\n%.2lf\n", tmp3, tmp3);
        puts("Whatever");
        return 0;
    }
    printf("%.2lf\n%.2lf\n", tmp3, tmp4);
    if (tmp1 > tmp2)
        puts("51Mole!!");
    else
        puts("51Seer!!");
}