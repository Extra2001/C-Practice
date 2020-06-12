#include<stdio.h>

int main()
{
    int a,sum,n,m;
    m=0;n=0,sum=0;
    while(1)
    {
        scanf(" %d",&a);
        getchar();
        if(a==-1)
        {
            break;
        }
        else if(a<60)
        {
            m++;
        }
        sum+=a;
        n++;
    }
    sum/=n;
    printf("Average:%d\n",sum);
    printf("Failed:%d\n",m);
}
