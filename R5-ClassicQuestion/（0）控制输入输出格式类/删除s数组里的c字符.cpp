#include <stdio.h>
#include <string.h>

int main()
{  char  s[80],c;
   int  j,k;
   printf("输入一个字符串: ");
   gets(s);
   printf("输入要删除的字符: ");
   c=getchar( );
   for(j=k=0;s[j]!= '\0';j++)
   	 if(s[j]!=c)
       s[k++]=s[j];
   s[k]= '\0';
   printf("处理后的字符串为：%s",s);
}

