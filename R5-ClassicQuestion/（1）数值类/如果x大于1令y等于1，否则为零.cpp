#include<stdio.h>
int main()
{
	int x,y;
	printf("enter x:");
	scanf("%d",&x);
	y=-1;
	//���x����1��y����1������Ϊ�� 
	if(x>0) y=1;
	else y=0;
	printf("x=%d,y=%d\n",x,y);
	return 0;	 	  
	
}
