#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (b == 0)
    {
        printf("ERROR. The divisor is ZERO.");
        return 0;
    }
    printf("%d div %d = %d ... %d", a, b, a / b, a % b);
}