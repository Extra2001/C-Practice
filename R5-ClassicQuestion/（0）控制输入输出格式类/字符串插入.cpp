#include<stdio.h>
#include<string.h>
int main()
{
    char c[11];
    int a[10],len;
    int i,j,max;
    gets(c);
    {
        while(c[i]!='\0')
        {
            a[i]=c[i];
            i++;
        }
        max=a[0];
        len = strlen(c);
        for(j=1;j<len;j++)
        {
            if(a[0]<a[j])
            {
                a[0]=a[j];
            }
        }
        printf("%c",a[0]);
    }
    return 0;
}
