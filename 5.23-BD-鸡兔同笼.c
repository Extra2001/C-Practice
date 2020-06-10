#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m;
    IN2(m, n);
    
    if (n < 0 || m < 0)
    {
        printf("Wrong number");
        return 0;
    }
    int tmp1 = n - 2 * m;
    if (tmp1 & 1 || tmp1 < 0)
    {
        printf("Wrong number");
        return 0;
    }
    
    tmp1 /= 2;
    if (m - tmp1 < 0)
    {
        printf("Wrong number");
        return 0;
    }
    printf("%d %d", m - tmp1, tmp1);
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}