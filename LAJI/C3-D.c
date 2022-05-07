#include <stdio.h>
int gcd(int m, int n)
{
    return m % n ? gcd(n, m % n) : n;
}
int main()
{
    int a, b, c, d;
    scanf("%d/%d%d/%d", &a, &b, &c, &d);
    int m = a * d + b * c, n = b * d;
    int gc = gcd(m, n);
    printf("%d/%d", (a * d + b * c) / gc, b * d / gc);
}