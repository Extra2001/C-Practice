#include<stdio.h>
int main()
{
	int flag=0,a;
	printf("����������:"); 
	scanf("%d",&a);
	if(a/3!=0)
	{
	flag=1;
	if(a/5!=0)
	{
	flag=1;
	

	
	if(a/7!=0)
	flag=1;
	else flag=0;
	}
	else
	flag=0;
	}
	else
	flag=0;
	
	
	if(flag==1)
	printf("���Ա�3,5,7������"); 
	if(flag==0)
	printf("�����Ա�3,5,7������");
	return 0;
	
 } 
