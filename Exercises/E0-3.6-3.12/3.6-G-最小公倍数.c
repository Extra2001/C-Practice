#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{

    int a, b, c, i;
    scanf("%d%d", &a, &b);
    if (a < b)
    {
        c = a;
        a = b;
        b = c;
    }
    for (i = a; i > 0; i++)
        if (i % a == 0 && i % b == 0)
        {
            printf("%d", i);
            break;
        }
}