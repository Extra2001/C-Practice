#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 0)
    {
        printf("1");
    }
    else if (n == 0)
    {
        printf("0");
    }
    else
    {
        printf("-1");
    }
}