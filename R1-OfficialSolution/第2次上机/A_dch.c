#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,a[205]={0};
int i,j;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",a+i);
    }

for ( i = 0; i < n; i++)
{
    for ( j = i+1; j < n; j++)
    {
        if(abs(a[i]-a[j])>10){
            printf("%d %d\n",i+1,j+1);
        }
    }
    
}

    
}