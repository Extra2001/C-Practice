#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

typedef long long LL;

//取模的性质：(a + -*b) % mod = (a % mod + -*b % mod) % mod
//a ^ b % p = ((a % p) ^ b) % p

LL divMod(LL num, LL mod)
{
    LL m = mod - 2;
    LL r = 1;
    while (m)
    {
        if (m & 1)
            r = r * num % mod;
        num = num * num % mod;
        m >>= 1;
    }
    return r;
}

int optimized_pow(int x, unsigned int n)
{
    int pw = 1;
    while (n > 0)
    {
        if (n & 1) // n & 1 等价于 (n % 2) == 1
            pw *= x;
        x *= x;
        n >>= 1; // n >>= 1 等价于 n /= 2
    }
    return pw;
}

int main()
{
    LL n;
    scanf("%llu", &n);
    LL res = (LL)sqrt(n);
    LL sum;
    sum = res % MOD;
    sum *= (res + 1) % MOD;
    sum %= MOD;
    sum *= (2 * res + 1) % MOD;
    sum %= MOD;
    sum *= divMod(6, MOD) % MOD;
    sum %= MOD;
    printf("%llu ", sum);
}