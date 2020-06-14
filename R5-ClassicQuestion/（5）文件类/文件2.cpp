#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch;
	FILE *fp;
	fp=fopen("F:\\习题\\文件.txt","w+");
	if(fp==NULL)
	{
		printf("打开错误");
		exit(0);
	}
	for(ch=0;ch<=127;ch++)
	{
		fputc(ch,fp);
		fputc('\n',fp);
	}
	rewind(fp);
	while(1)
	{
		if((ch=fgetc(fp))==EOF)
		break;
		putchar(ch);
	}
	fclose(fp);
	return 0;
}
