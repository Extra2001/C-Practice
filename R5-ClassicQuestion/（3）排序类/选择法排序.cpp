#include<stdio.h>
int main()
{//选择法排序 
	int a[4],i,j,t,temp;
	printf("请输入4个整数：");
	for(i=0;i<4;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<3;i++)
	{
		t=i;
		for(j=i+1;j<4;j++)
		{
			if(a[t]>a[j])
			{
				t=j;
			}
		}
		if(t!=i)
		{
			temp=a[i];
			a[i]=a[t];a[t]=temp;
		}
	}
	printf("排序为："); 
	for(i=0;i<4;i++)
	{
		printf("%d ",a[i]);
	}
}

