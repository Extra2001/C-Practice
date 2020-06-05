#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//组合数
int C(int n, int m)
{
    return getFactorial(n) / (getFactorial(m) * getFactorial(n - m));
}

//阶乘
int getFactorial(int n)
{
    if (n <= 1)
        return 1;
    return n * getFactorial(n - 1);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    int r = a % b;
    return GCD(b, r);
}

//判断是否是质数的独立版本
int isPrime(int a)
{
    if (a == 2)
        return 1;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}


//生成质数表
int primes[8716];

int isPrime(int n)
{
    int i;
    for (i = 0; primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
            return 0;
    }
    return 1;
}

void init_primes(int Q)
{
    int count = 3, num, step;
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    num = 7;
    step = 2;
    while (num <= Q)
    {
        step = 6 - step;
        if (isPrime(num))
            primes[count++] = num;
        num += step;
    }
}

//除法取余
int divMod(int num, int mod)
{
    int m = mod - 2;
    int r = 1;
    while (m)
    {
        if (m & 1)
            r = r * num % mod;
        num = num * num % mod;
        m >>= 1;
    }
    return r;
}

//快速求幂
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