#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,k;
	scanf("%d",&n);
	for(i=0;i<32;i++)
	{
		k=1<<i;
		if(n==k)
		{
			printf("true %d",i);
			return 0;
		}
	}
	printf("false");
	return 0;
}
