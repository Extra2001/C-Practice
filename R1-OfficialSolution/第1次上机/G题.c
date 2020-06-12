#include<stdio.h>
int main()
{
    int n,a,b;
    scanf("%d",&n);
    while(1)
    {
        n++;
        a=n/100;
        b=n%100;
        if(n>=9999)
        {
            printf("-1\n");
            break;
        }
        else if(n==a*a+b*b)
        {
            printf("%d\n",n);
            break;
        }
    }
    return 0;
}
