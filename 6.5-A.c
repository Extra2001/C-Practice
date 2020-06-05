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
    int n;
    IN1(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        IN3(a, b, c);
        int d, e, f;
        d = a * a + b * b;
        e = b * b + c * c;
        f = c * c + a * a;
        if (d == c * c || e == a * a || f == b * b)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}