 #include<stdio.h>
int main(void)
{
	char ch;
	int a=0,b=0,c=0,d=0,e=0;
	while((ch=getchar())!='\n')
	{
		if(ch>='a'&&ch<='z')
	        a++;
		else if(ch>='A'&&ch<='Z')
			b++;
		else if(ch>='0'&&ch<='9')
			c++;
		else if(ch==' ')
			d++;
		else
			e++;
	
	}
printf("Сд��ĸ�У�%d��",a);
printf("\n");
printf("��д��ĸ�У�%d��",b);
printf("\n");
printf("�����У�%d��",c);
printf("\n");
printf("�ո��У�%d��",d);
printf("\n");
printf("�����ַ��У�%d��",e);//һ�������ַ��൱������Ӣ���ַ��������е�С���� 

	return 0;
}

