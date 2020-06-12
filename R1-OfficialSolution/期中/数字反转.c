#include <stdio.h>
#include <string.h>

char str[5000];

int main()
{
    int i, len, begin = 0;
    ;
    scanf("%s", str);
    len = strlen(str);
    for (i = len - 1; i >= 0; i--)
    {
        if (begin == 0)
        {
            begin = str[i] - '0';  //0-》0；1，2，3-》非0
            // continue;
        }
        if(begin){
        putchar(str[i]);
        }
    }
    if(begin==0){
        printf("0");
    }
}