#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);
void OutInSystem(int num, int System);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    OutInSystem(n, 2);
    OutInSystem(n, 8);
    OutInSystem(n, 16);
    // fclose(stdin);
}

void OutInSystem(int num, int System)
{
    int m, i = 0;
    int b[1000];
    if (num == 0)
    {
        printf("0\n");
        return;
    }
    while (num)
    {
        b[i] = num % System;
        i++;
        num = num / System;
    }
    for (i = i - 1; i >= 0; i--)
    {
        if (abs(b[i]) == 10)
            printf("A");
        else if (abs(b[i]) == 11)
            printf("B");
        else if (abs(b[i]) == 12)
            printf("C");
        else if (abs(b[i]) == 13)
            printf("D");
        else if (abs(b[i]) == 14)
            printf("E");
        else if (abs(b[i]) == 15)
            printf("F");
        else
            printf("%d", abs(b[i]));
    }
    printf("\n");
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}