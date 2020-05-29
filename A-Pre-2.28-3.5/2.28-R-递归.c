#include <math.h>
#include <stdio.h>
int keguazi(int a);
int main()
{
    int b;
    scanf("%d", &b);

    printf("%d", keguazi(b));
    return 0;
}
int keguazi(int a)
{
    if (a == 1 || a == 0)
    {
        return 1;
    }
    if (a < 1)
    {
        return 0;
    }
    if (a == 2)
    {
        return 2;
    }
    return keguazi(a - 1) + keguazi(a - 2) + keguazi(a - 3);
}