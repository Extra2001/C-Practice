#include <stdio.h>

int Judge(int n)
{
    int i, m;
    m = (int)sqrt((double)n);
    for (i = 2; i <= m; i++)
        if (n % i == 0)
            break;
    if (i > m)
    {
        int a = 0;
        int mm = n;
        while (n)
        {
            int temp = n % 10;
            a *= 10;
            a += temp;
            n /= 10;
        }
        if (a == mm)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    for (int i = 0; i < 1000000;i++){
        if(Judge(i)){
            printf("%d\n", i);
        }
    }
}