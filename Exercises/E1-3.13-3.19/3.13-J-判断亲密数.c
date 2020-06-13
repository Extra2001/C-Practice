#include <stdio.h>
//数学家的浪漫
int main()
{
    int a, b, i, k = 1, m = 1;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a == b)
        {
            printf("N\n");
            continue;
        }
        k = 1;
        m = 1;
        for (i = 2; i <= a / 2; i++)
        {
            if (a % i == 0)
                m += i;
        }
        if (m != b)
        {
            printf("N\n");
            continue;
        }
        for (i = 2; i <= b / 2; i++)
        {
            if (b % i == 0)
                k += i;
        }
        if (k == a)
            printf("Y\n");
        else
            printf("N\n");
    }
}