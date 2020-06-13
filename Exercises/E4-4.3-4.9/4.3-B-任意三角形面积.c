#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);
#define EPSILON 1e-8

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

int main()
{

    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    point p1, p2, p3;
    scanf("%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
    printf("%.4lf", areaOfTri(&p1, &p2, &p3));
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}