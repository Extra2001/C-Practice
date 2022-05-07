#include <stdio.h>

int main()
{
    long long a;
    scanf("%lld", &a);
    for (int i = 0; i < 64; i++)
    {
        if ((a >> i) & 1)
            printf("%lld\n", 1LL << i);
    }
}