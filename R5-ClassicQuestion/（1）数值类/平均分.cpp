#include<stdio.h>
#define N 40
double Average(int score[],int n);
void ReadScore(int score[],int n);
int main()
{
	int score[N],n;
	int aver;
	printf("����ѧ������n:");
	scanf("%d",&n);
	ReadScore(score,n);
	aver=Average(score,n);
	printf("ƽ�����ǣ�%d",aver);
	return 0; 
 } 
double Average(int score[],int n)
{
	int i,sum=0,s;
	for(i=0;i<n;i++)
	{
		sum+=score[i];
	}
	s=sum/n;
	return s;
 } 
void ReadScore(int score[],int n)
{
	int i;
	printf("����ɼ���");
	for(i=0;i<n;i++)
	{
		scanf("%d",&score[i]);
	 } 
 } 
