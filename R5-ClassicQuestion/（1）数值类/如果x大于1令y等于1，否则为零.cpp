#include<stdio.h>
int main()
{
	int x,y;
	printf("enter x:");
	scanf("%d",&x);
	y=-1;
	//如果x大于1令y等于1，否则为零 
	if(x>0) y=1;
	else y=0;
	printf("x=%d,y=%d\n",x,y);
	return 0;	 	  
	
}
