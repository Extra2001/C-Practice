#include<stdio.h>
main()
{
	int x,y;
	printf("������x��ֵ��");
	scanf("%d",&x);
	if(x<1) y=x;
    if(1<=x&&x<10) y=2*x-1;
	if(x>=10) y=3*x-11;
	 printf("yֵΪ��%d",y);
}
