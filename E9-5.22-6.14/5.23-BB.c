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
    long long xishu = 1, cishu = 0;
    long long tmp1, tmp2;
    while (1)
    {
        scanf("%lld %lld", &tmp1, &tmp2);
        if (tmp1 == 0 && tmp2 == 0)
            break;
        xishu *= tmp1;
        cishu += tmp2;
    }
    printf("%lld*x^%lld", xishu, cishu);
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}