// 括号序列匹配判定，栈的应用
#include <stdio.h>
#include <stdlib.h>
char str[100100];
int index[100100],stack[100100];
int main()
{
    scanf("%s",str);
    int top=0,len;
    len=strlen(str);
    int i;
    for(i=0;i<len;i++)
    {
        if(str[i]==')'||str[i]=='}')
        {
            if((str[stack[top]]=='('&&str[i]==')')||(str[stack[top]]=='{' &&str[i]=='}'))
                {
                    index[i]=stack[top];
                    index[stack[top]]=i;
                    top--;
                }
            else {printf("NO\n");return 0;}
        }
        else stack[++top]=i;
    }
    if(top>0) printf ("NO\n");
    else {
        for(i=0;i<len;i++)
            printf ("%d\n",index[i]+1);
    }

    return 0;
}
