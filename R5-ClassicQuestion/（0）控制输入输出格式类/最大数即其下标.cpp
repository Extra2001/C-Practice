#include<stdio.h>
int main()
{
	int a[50],i,max,k,n;
	while(scanf("%d",&n)!=EOF)
	{
	if(n!=0)
	{
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	max=a[0];
	k=0;
	for(i=1;i<10;i++)
		if(max<a[i])
	{
		max=a[i];
		k=i+1;
		}
		printf("%d %d\n",k,max);
		k=0;
		max=0;
		}
		else break;
		n=0;
		
		
		}
return 0;
}

