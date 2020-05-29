#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int comp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int main()
{
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    init_primes(90007);
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int* b = (int *)bsearch(&n, primes, 8716, sizeof(int), comp);
        printf("%d\n", *(b + m));
    }
    //fclose(stdin);
}