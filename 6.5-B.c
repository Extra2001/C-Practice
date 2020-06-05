#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int a, b, c, d;
    IN2(a, b);
    IN2(c, d);
    int di = c * c + d * d;
    double e = (a * c + b * d) / (double)di, f = (b * c - a * d) / (double)di;
    printf("%.2lf %.2lf", e, f);
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}