#include<stdio.h>
int main()
{
    int a[6],b[6];
    int i , sum=0;
    for(i=0;i<6;i++)
    {
        scanf("%d",&a[i]);
        //getchar();
    }
    getchar();
    for(i=0;i<6;i++)
    {
        scanf("%d",&b[i]);
        //getchar();
    }
    for(i=0;i<6;i++)
    {
        if(a[i]>b[i])
        {
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}
