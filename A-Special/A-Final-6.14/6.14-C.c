#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

char a[100055];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    gets(a);
    char *p = a;
    int cnt = 0;
    while (p = strstr(p, "qaq"))
    {
        cnt++;
        p += 2;
    }
    p = a;
    while (p = strstr(p, "qwq"))
    {
        cnt++;
        p += 2;
    }
    printf("%d", cnt);
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}