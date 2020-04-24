#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int x;
    scanf("%d", &x);
    int n = x;
    while (1)
    {
        if(x==2){
            printf("1");
            break;
        }
        if (Judge(x))
        {
            x = x / 2 + 1;
            if (n > x)
                printf("%d", x);
            else
                printf("%d", n);
            break;
        }
        else
        {
            x++;
        }
    }
    //fclose(stdin);
}