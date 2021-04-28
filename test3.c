#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
char a[1005][102];
int main()
{
	freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
	int ch;
	while ((ch = getchar()) != -1)
	{
		if(!(ch == ' ' || !isprint(ch)))
		printf("%c", ch);
	}
}