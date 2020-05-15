#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long res = (unsigned long long)sqrt(n);
    unsigned long long sum;
    sum = ((res % 1000000007) * ((res + 1) % 1000000007) * ((2 * res + 1) % 1000000007)) % 1000000007;
    sum /= 6;
    printf("%d", sum);
}