#include <stdio.h>
#include <string.h>

int main()
{  char  s[80],c;
   int  j,k;
   printf("����һ���ַ���: ");
   gets(s);
   printf("����Ҫɾ�����ַ�: ");
   c=getchar( );
   for(j=k=0;s[j]!= '\0';j++)
   	 if(s[j]!=c)
       s[k++]=s[j];
   s[k]= '\0';
   printf("�������ַ���Ϊ��%s",s);
}

