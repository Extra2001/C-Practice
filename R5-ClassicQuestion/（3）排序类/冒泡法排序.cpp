#include<stdio.h>
int main()
{//ð�ݷ����� 
int a[4],n=4,i,j,t;
printf("������4��������");
for(i=0;i<4;i++)
{
	scanf("%d",&a[i]);
 } 
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];	a[j]=a[j+1];a[j+1]=t;
			}
		}
	}
printf("����Ϊ��"); 
for(i=0;i<4;i++)
{
printf("%d ",a[i]);
}
}

