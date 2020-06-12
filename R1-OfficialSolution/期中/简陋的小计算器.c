#include <stdio.h>

int main()
{
    int a, b;
    char c;
    int f;
    while (scanf("%d %c %d", &a, &c, &b) > 0)
    {
        switch (c)
        {
        case '+':
            f = a + b;
            break;
        case '-':
            f = a - b;
            break;
        case '*':
            f = a * b;
            break;
        case '/':
            if (b == 0)
            {
                printf("Runtime Error(SIGFPE)\n");
                continue;
            }
            else
            {
                printf("%.2f\n", (double)a / b);
                continue;
            }
            break;
        case '%':
            if (b == 0)
            {
                printf("Runtime Error(SIGFPE)\n");
                continue;
            }
            else
            {
                f = a % b;
            }
        }
        printf("%d\n", f);
    }
}