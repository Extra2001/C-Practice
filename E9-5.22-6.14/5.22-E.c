#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    double l, r;
    while (~scanf("%lf%lf", &l, &r))
        printf("%.2lf\n", (PI * r * r * sqrt(l * l - r * r)) / 3.0);

    // fclose(stdin);
}
