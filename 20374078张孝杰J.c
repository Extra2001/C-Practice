#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
char s[120];
char a[120];
int main() {
    scanf("%s",s);
    strcpy(a,s);
    int m=strlen(s);
    int n=m/2;
    for(int i=0;i<n;i++)
    {
        s[m-i-1]=s[i];
    }

    if((strcmp(a,s)<0)||(strcmp(a,s)==0))
        printf("%s",s);

    else
    {
        s[n-1]+=1;
        for(int i=0;i<n;i++)
    {
        s[m-i-1]=s[i];
    }
        printf("%s\n",s);
    }
    return 0;
}