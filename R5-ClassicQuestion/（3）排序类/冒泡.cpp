//��д�������ݺ���������ð�ݷ���ѡ�񷨣�������������������10�����ݵ����롢�������������������н��в��ԡ�
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void inputData(int a[],int n);     //�������ݸ�ֵ
void selectedSort(int a[],int n);  //ѡ������
void bubbleSort(int a[],int n);    //ð������
void outputData(int a[],int n);    //�������
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
	printf("������%d��������\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void selectedSort(int a[],int n)  //ѡ������
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
void bubbleSort(int a[],int n)    //ð������
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
	printf("����Ϊ��\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

