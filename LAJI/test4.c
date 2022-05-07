#include <stdio.h>
#include <stdlib.h>
int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int a, b, c, t, A, B, x, y;
    double p;

    scanf("%d%d", &a, &b);
    A = a;
    B = b;
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }
    if (a == 0)
    {
        printf("0\n");
    }
    else
    {
        if (b < a)
        {
            t = a;
            a = b;
            b = t;
        }
        c = a % b;
        while (c != 0)
        {
            a = b;
            b = c;
            c = a % b;
        }
        p = (A / b) / (B / b);
        x = p;
        y = (A - x * B) / b;
        if (abs(A) < abs(B))
        {
            printf("%d/%d\n", (A / b), (B / b));
        }
        else
        {
            if (abs(B) == b)
            {
                printf("%d\n", A / b);
            }
            else
            {
                if (A * B > 0)
                {
                    printf("%d+%d/%d\n", x, y, B / b);
                }
                else
                {
                    printf("%d%d/%d\n", x, y, B / b);
                }
            }
        }
    }
    return 0;
}