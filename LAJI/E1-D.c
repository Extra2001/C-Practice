#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEndR(char *base);

int cmp(const void *a, const void *b)
{
    double *e = (double *)a, *f = (double *)b;
    return *e - *f > 0 ? 1 : -1;
}

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    double p, q;
    scanf("%lf%lf", &p, &q);
    if (q * q > p * p * p)
    {
        double a = q + sqrt(q * q - p * p * p), b = q - sqrt(q * q - p * p * p);
        printf("%.10lf", (a < 0 ? (-1 * pow(-1 * a, 1.0 / 3.0)) : pow(a, 1.0 / 3.0)) + (b < 0 ? (-1 * pow(-1 * b, 1.0 / 3.0)) : pow(b, 1.0 / 3.0)));
        return 0;
    }
    double x[3];
    x[0] = 2 * sqrt(p) * cos(1.0 / 3.0 * acos(q / (pow(p, 1.5))));
    x[1] = 2 * sqrt(p) * cos(1.0 / 3.0 * acos(q / (pow(p, 1.5))) + 2.0 / 3.0 * acos(-1));
    x[2] = 2 * sqrt(p) * cos(1.0 / 3.0 * acos(q / (pow(p, 1.5))) + 4.0 / 3.0 * acos(-1));
    qsort(x, 3, sizeof(x[0]), cmp);
    printf("%.10lf %.10lf %.10lf", x[0], x[1], x[2]);
    // fclose(stdin);
}