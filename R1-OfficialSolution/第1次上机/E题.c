#include<stdio.h>

int main ()
{
    int n ,i , sum1=0,sum2=0;
    int x[200],y[200];
    double average;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        sum1+=x[i];
        sum2+=y[i];
        getchar();
    }
    average=(0.2*sum1+0.8*sum2)/n;
    printf("%.5lf",average);
    return 0;
}
