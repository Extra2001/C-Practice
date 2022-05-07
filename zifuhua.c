/*
    Please use GB2312 encoding to open this file
*/
#include <stdio.h>
#include <string.h>
#define MAXLENGTH 10005

char str[100][MAXLENGTH];
void change(char s[]);

int main()
{
    /*
        使用方法：运行后输入字符画，回车后输入Ctrl+Z（EOF）再回车
        ，输出代码，复制到新程序的main函数中即可输出字符画。
    */
    int i, j;
    for (i = 0; gets(str[i]) != NULL; i++)
        change(str[i]);
    puts("The output is as following: ");
    for (j = 0; j < i; j++)
        printf("puts(\"%s\");\n", str[j]);
}

void change(char s[])
{
    int i, n = strlen(s), cnt;
    char temp[MAXLENGTH] = {0};
    while (s[n - 1] == '\r')
        s[n - 1] = '\0', n--; //删除结尾的\r
    for (i = 0, cnt = 0; i < n; i++, cnt++) //检查每个字符是否转义
    {
        switch (s[i])
        {
        case '\r':
            break;
        case '\n':
            temp[cnt] = '\\';
            temp[++cnt] = 'n';
            break;
        case '\"':
            temp[cnt] = '\\';
            temp[++cnt] = '\"';
            break;
        case '\\':
            temp[cnt] = '\\';
            temp[++cnt] = '\\';
            break;
        default:
            temp[cnt] = s[i];
            break;
        }
    }
    strcpy(s, temp); // 复制回原来的数组
}