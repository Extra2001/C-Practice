#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);
#define EPSILON 1e-8

int TrimEndR(char *base);


typedef struct po
{
    double x, y;
} point;

double areaOfTri(point *p1, point *p2, point *p3)
{
    double s1 = p2->x * p3->y - p2->y * p3->x;
    double s2 = p1->y * p3->x - p1->x * p3->y;
    double s3 = p1->x * p2->y - p2->x * p1->y;
    return 0.5 * (s1 + s2 + s3);
}

point a[505];

int main()
{

    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    IN1(n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    double min = 1e100;
    for (int i = 0; i < n; i++)
        for (int j = 1 + i; j < n; j++)
            for (int k = 1 + j; k < n; k++)
            {
                double tmp = fabs(areaOfTri(&a[i], &a[j], &a[k]));
                if (min > tmp)
                    min = tmp;
            }
    printf("%.4lf", min);
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}