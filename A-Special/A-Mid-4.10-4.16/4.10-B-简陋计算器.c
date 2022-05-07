#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int a, b, re;
    double red;
    char op;
    while (~scanf("%d %c %d", &a, &op, &b))
    {
        switch (op)
        {
        case '+':
            re = a + b;
            printf("%d\n", re);
            break;
        case '-':
            re = a - b;
            printf("%d\n", re);
            break;
        case '*':
            re = a * b;
            printf("%d\n", re);
            break;
        case '/':
            if (b == 0)
            {
                printf("Runtime Error(SIGFPE)\n");
            }
            else
            {
                red = (double)a / (double)b;
                printf("%.2lf\n", red);
            }
            break;
        case '%':
            if (b == 0)
            {
                printf("Runtime Error(SIGFPE)\n");
            }
            else
            {
                printf("%d\n", a % b);
            }
            break;
        default:
            break;
        }
    }
    fclose(stdin);
}