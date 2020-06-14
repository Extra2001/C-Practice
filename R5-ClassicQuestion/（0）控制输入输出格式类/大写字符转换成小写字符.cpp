#include<stdio.h>
int main()
{
char ch;
ch=getchar();
if(ch>='A'&&ch<='Z')
ch=ch+32;
printf("%c",ch);
return 0;
}

