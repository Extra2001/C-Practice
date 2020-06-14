#include<stdio.h>
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*n-i;j++)
        {
            if(j<i)printf(" "); 
            else printf("#");
        }
        printf("\n");
    }
    return 0; 
}
