#include<stdio.h>
int main()
{
	float a,b,c;
	printf("��������������");
	scanf("%f %f %f",&a,&b,&c);
	if(a<b)
	a=b;
	if(a<c)
	a=c;
	printf("�����Ϊ��%f",a);
}
