#include <stdio.h>

int main()
{
    unsigned long long N, k, a;
    while (scanf("%llu%llu%llu", &N, &k, &a) != EOF)
    {
        k %= N;
        printf("%llu\n", (((a << k) | (a >> (N - k))) & ((1ULL << N) - 1ULL)));
    }
}