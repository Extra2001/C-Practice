#include<stdio.h>
// 把一个数字变成字符串，而且不用scanf，而是用循环
int main()
{
	char s[100]= {0};

	int a=123,i=0;

// a为0的话，也要加一个0进到数组里啊。 

	do {
		s[i]=a%10+'0';
		a/=10;
		i++;
	} while(a);

	;
}
