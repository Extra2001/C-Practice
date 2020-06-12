#include <stdio.h>

int primes[70000] = {2}, top = 1;

int main()
{
    int m, n, j, i, isPrime = 0;

    for (i = 3; i <= 90007; ++i)
    {
        isPrime = 1;
        for (j = 0; j < top && primes[j] * primes[j] <= i; ++j)
        {
            if (i % primes[j] == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
        {
            primes[top] = i;
            top++;
        }
    }

    while (scanf("%d %d", &n, &m) > 0)
    {
        for (i = 0; i < top; ++i)
        {
            if (primes[i] == n)
            {
                break;
            }
        }
        printf("%d\n", primes[i + m]);
    }
}