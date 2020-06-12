#include<stdio.h>
int main()    
{
	char str[110];
	fgets(str,110,stdin);
	printf("%s",str+3);
	return 0;
}

