#include <stdio.h>

int main()
{
	freopen("./in3.txt", "r", stdin);
    char s[50]={0};
    gets(s);
    getchar();
	fclose(stdin);
}