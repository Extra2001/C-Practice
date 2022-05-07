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
    int n, i, j;
    scanf("%d", &n);
    for (i = n; i >= 1; i--) // 共n行，从下往上，分别是第 1 到第 n 行
    {
        for (j = 1; j <= n - i; j++) // 第i行，先打印 n-i 个空格
            printf(" ");
        for (j = 1; j <= 2 * i; j++) // 第i行，接着打印 2i-1 个星
        {
            if (j == 1)
                printf("\\");
            else if (j == 2 * i)
                printf("/");
            else
                printf(" ");
        }
        printf("\n");
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}