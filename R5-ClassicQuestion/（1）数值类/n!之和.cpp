#include<stdio.h>
int main()
{
	int i,n;
	double sum=0.0,f=1.0;
	printf("请输入n的值：");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=f*i;
		sum=sum+f;
	}
	printf("n阶之和为：%.0lf",sum);
	return 0;
}

