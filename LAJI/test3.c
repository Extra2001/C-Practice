
#include <stdio.h>
int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int a = 0, b = 0, c, d;
    int Max = 0, Min = 0;
    while ((scanf("%d %d", &a, &b)) != EOF)
    {
        c = a, d = b;
        if (a < 0)
        {
            a = -a;
        }
        if (b < 0)
        {
            b = -b;
        }
        if (a >= b)
        {
            Max = a;
            Min = b;
        }
        else
        {
            Max = b;
            Min = a;
        }
        while (Min != 0)
        {
            int Temp = Max % Min;
            Max = Min;
            Min = Temp;
        }
        if ((a < b) && ((c > 0 && d < 0) || (d > 0 && c < 0)))
        {
            printf("-%d/%d\n", a / Max, b / Max);
        }
        else if ((a < b) && ((c > 0 && d > 0) || (d < 0 && c < 0)))
        {
            printf("%d/%d\n", a / Max, b / Max);
        }
        else if (((c > 0 && d < 0) || (d > 0 && c < 0)) && ((a > b) && (b != Max) && (-b != Max)))
        {
            int x = (a - (a % b)) / b;
            printf("-%d-%d/%d\n", x, (a - (b * x)) / Max, b / Max);
        }
        else if ((b == Max) && ((c > 0 && d < 0) || (d > 0 && c < 0)))
        {
            printf("-%d\n", a / b);
        }
        else if ((b == Max) && ((c > 0 && d > 0) || (d < 0 && c < 0)))
        {
            printf("%d\n", a / b);
        }
        else
        {
            int s = (a - (a % b)) / b;
            printf("%d+%d/%d\n", s, (a - (b * s)) / Max, b / Max);
        }
    }
    return 0;
}
