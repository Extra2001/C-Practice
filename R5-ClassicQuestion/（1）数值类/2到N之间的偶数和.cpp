#include <stdio.h>
int Sum(int m, int n)
{
    int s;
    for (s = 0, m += (m & 1); m <= n; s += m, m += 2)
        ;
    return s;
}
int main()
{
    int m = 0, n;
    if (scanf("%d", &n) != 2 || m < 0 || m > n)
    {
        return 0;
    }
    printf("%d", Sum(m, n));
    return 0;
}
