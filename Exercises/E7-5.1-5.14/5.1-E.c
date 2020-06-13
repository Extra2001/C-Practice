#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

long long a[1000005] = {0};
long long b[1000005] = {0};

void gen(int n)
{
    b[1] = b[2] = b[3] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        b[i] = (b[i - 1] + b[i - 2] + b[i - 3]) % MOD;
        a[i] = (a[i - 1] + b[i]) % MOD;
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int q, tmp;
    IN1(q);
    gen(1000000);
    for (int i = 0; i < q; i++)
    {
        IN1(tmp);
        printf("%lld\n", a[tmp]);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}