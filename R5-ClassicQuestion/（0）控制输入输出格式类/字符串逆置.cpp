#include <stdio.h>
#include <string.h>
void reverse(char str[]);
int main()
{
	char str[50];
	puts("������һ���ַ�����");
	gets(str);
	puts("ת������ַ���Ϊ��");
	reverse(str);
	puts(str);
}
void reverse(char str[])
{
	int i,len;
	char ch;
	len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		ch=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=ch;
	}
}

