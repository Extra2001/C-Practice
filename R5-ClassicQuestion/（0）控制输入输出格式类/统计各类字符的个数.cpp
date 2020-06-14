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
printf("小写字母有：%d个",a);
printf("\n");
printf("大写字母有：%d个",b);
printf("\n");
printf("数字有：%d个",c);
printf("\n");
printf("空格有：%d个",d);
printf("\n");
printf("其他字符有：%d个",e);//一个中文字符相当于两个英文字符，所以有点小错误 

	return 0;
}

