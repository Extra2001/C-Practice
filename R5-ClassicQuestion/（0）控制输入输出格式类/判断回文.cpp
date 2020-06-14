#include <stdio.h>
#include <string.h>
int main()
{ char s[100];
  int i,j,n,k;
  while(k<10)
  {
  gets(s); 
  
  n=strlen(s);
  for(i=0,j=n-1;i<j;i++,j--)
    if(s[i]!=s[j])   break;
  if(i>=j) printf("Yes\n");
  else   printf("No\n");
  
  k=k+1;
}}

