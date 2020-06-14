#include<stdio.h>
int main()
{   int m,n,sum=0,i,t;
    scanf("%d%d",&m,&n);
	if(m>n)
	{t=m;m=n;n=t;
	}
	for(i=m;i<=n;i++)
    {if(i%3==0&&i%5==0)
    sum=sum+1;
    
	}
	printf("%d",sum);
}
