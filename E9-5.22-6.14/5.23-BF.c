#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);
char map[105][10005];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    IN1(n);
    int tmp = n * n, cent = tmp / 2;
    while (n)
    {
        tmp = n * n;
        if (tmp & 1)
        {
            map[n][cent] = '$';
        }
        else
        {
            map[n][cent] = '@';
        }
        int t = tmp / 2;
        for (int i = 1; i <= t; i++)
        {
            map[n][cent - i] = '$';
            map[n][cent + i] = '$';
        }
        for (int i = 0; !(map[n][i]); i++)
            map[n][i] = ' ';
        n--;
    }
    for (int i = 1; map[i][0]; i++)
    {
        puts(map[i]);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}