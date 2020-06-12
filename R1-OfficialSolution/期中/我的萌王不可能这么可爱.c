#include <stdio.h>

int main()
{

    int a;
    int res = 0;
    int n,i;

    while (scanf("%d", &n) > 0)
    {
        res = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a);

            res += (a == i);
        }
        printf("%d\n", res);
    }
}