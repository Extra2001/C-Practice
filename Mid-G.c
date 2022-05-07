#include <stdio.h>

long long d(long long x, long long y)
{
    long long tmp = x;
    if (x < y)
    {
        x = y;
        y = tmp;
    }
    if (y == 0)
        return 0;
    return 4 * y * (x / y) + d(x % y, y);
}

int main()
{
    long long x, y;
    while (~scanf("%lld%lld", &x, &y))
        printf("%lld\n", d(x, y));
}