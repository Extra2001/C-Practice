#include<stdio.h>
int main()
{
	int flag=0,a;
	printf("请输入数字:"); 
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
	printf("可以被3,5,7整除！"); 
	if(flag==0)
	printf("不可以被3,5,7整除！");
	return 0;
	
 } 
