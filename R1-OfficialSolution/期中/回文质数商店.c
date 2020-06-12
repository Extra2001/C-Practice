#include <stdio.h>

int isPrime(int n)
{
    int i;
    if (n < 2)
    {
        return 0;
    }
    for (i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isBackWen(int n)
{
    int b = 0, m;
    m = n;
    while (n)
    {
        b = b * 10 + n % 10;
        n /= 10;
    }
    return m == b;
}

int main()
{
    int x;
    int cost;
    scanf("%d", &x);
    cost=x;
    while (1)
    {
        // printf("%d",x/2+x%2);
        if(isPrime(x)&&isBackWen(x)){
            if((x/2+x%2)<cost){
                printf("%d",x/2+x%2);
            }else
            {
                printf("%d",cost);
            }
            return 0;
        }
        x++;
    }
    return 0;
}