#include <stdio.h>
#include <string.h>
char str[10005] = {0};
char target[20] = {0};
int main()
{
    char *begin, *end;
    int len, lim;
    scanf("%s", str);
    scanf("%s", target);
    lim = strlen(str);
    len = strlen(target);
    begin = str;
    while (begin <=(str + lim))
    {
        end = strstr(begin, target);
        if (end != NULL)
        {
            *end = '\0';
            printf("%s;\n", begin);
            begin = end + len;
        }
        else
        {
            printf("%s;\n", begin);
            return 0;
        }
    }
}