#include<stdio.h>
int main()
{
	int i,n;
	double sum=0.0,f=1.0;
	printf("������n��ֵ��");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=f*i;
		sum=sum+f;
	}
	printf("n��֮��Ϊ��%.0lf",sum);
	return 0;
}

