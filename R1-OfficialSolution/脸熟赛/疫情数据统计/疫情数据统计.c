#include <stdio.h>
int main()
{
	int n,i,j,k=0,l=0,m=0;
	int add[1001]={0},cure[1001]={0};
	int stock[1001]={0},change[1001]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&add[i],&cure[i]);
		stock[i]=stock[i-1]+add[i]-cure[i];
		change[i]=add[i]-cure[i];
	}
	for(i=1;i<=n;i++)
	{
		if(change[i]>change[k]) k=i;
		if(stock[i]>stock[l]) l=i;
		if(stock[i]!=0) m=i;
	}
	m++;
	printf("%d %d %d",k,l,m);
	return 0;
}
