#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);
char a[1005];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    scanf("%s", a);
    int n, tmp1, tmp2;
    IN1(n);
    for (int i = 0; i < n; i++)
    {
        IN2(tmp1, tmp2);
        sectionReverse(a, tmp1, tmp2);
    }
    puts(a);
    // fclose(stdin);
}

void sectionReverse(char *str, int l, int r)
{
    int len = r - l + 1;
    for (int i = 0; i < len / 2; i++)
    {
        int tmp = str[l + i];
        str[l + i] = str[r - i];
        str[r - i] = tmp;
    }
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}