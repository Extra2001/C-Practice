#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

int t;
int n, m;

int getqun(int curn)
{
    int tmp1 = curn + m, tmp2 = curn - m;
    if ((tmp1 & 1) || (tmp2 & 1) || tmp2 <= 0)
        return 1;
    return getqun(tmp1 / 2) + getqun(tmp2 / 2);
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &m);
        printf("Case #%d: %d\n", i + 1, getqun(n));
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}