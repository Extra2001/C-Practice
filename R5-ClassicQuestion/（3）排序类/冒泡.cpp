//编写输入数据函数、排序（冒泡法、选择法）函数、输出函数，完成10个数据的输入、排序和输出，在主函数中进行测试。
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void inputData(int a[],int n);     //数组数据赋值
void selectedSort(int a[],int n);  //选择排序
void bubbleSort(int a[],int n);    //冒泡排序
void outputData(int a[],int n);    //输出数据
int main()
{
	int a[SIZE];
	inputData(a,SIZE);
	outputData(a,SIZE);
	selectedSort(a,SIZE);
	bubbleSort(a,SIZE);
	outputData(a,SIZE);
}
void inputData(int a[],int n)
{
	int i;
	printf("请输入%d个整数：\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void selectedSort(int a[],int n)  //选择排序
{
int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				t=a[j]; a[j]=a[i]; a[i]=t;
			}
		}
	}
}
void bubbleSort(int a[],int n)    //冒泡排序
{
	int i,j;
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
}
void outputData(int a[],int n)
{
	int i;
	printf("数组为：\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

