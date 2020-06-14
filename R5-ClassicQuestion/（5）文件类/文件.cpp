#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	fp=fopen("fasc.txt","w");
	if(fp==NULL)
	{
		printf("NO");
		exit(0);
	}
	for(ch=0;ch<=127;ch++)
	fputc(ch,fp);
	fclose(fp);
	exit(0);
}
