#include<stdio.h>
int main()
{
	float a,b,c;
	printf("请输入三个数：");
	scanf("%f %f %f",&a,&b,&c);
	if(a<b)
	a=b;
	if(a<c)
	a=c;
	printf("最大数为：%f",a);
}
