#include <stdio.h>
#include <string.h>

char ans[20005] = {0};
char tmp[20005] = {0};

int empty(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int main()
{
    int i, len;
    int max = 0;
    while (gets(tmp) != NULL)
    {
        len = strlen(tmp);
        for (i = len - 1; i >= 0; --i)
        {
            if (!empty(tmp[i]))
            {
                len = i + 1;
                tmp[len] = 0;
                break;
            }
        }
        if (len >= max)
        {
            max = len;
            strcpy(ans, tmp);
        }
    }

    printf("%d %s", max,ans);
}
