#include <stdio.h>
#include <string.h>

char s[2009] = {0};
char from[100], to[100];
char ans[10000] = {0};

int main()
{
    int i, len, lenFrom, dx = 0, changed = 0;
    gets(s);
    gets(from);
    gets(to);
    len = strlen(from);
    
    for (i = len - 1; i >= 0; i--)
    {
        if (from[i] == ';')
        {
            from[i] = 0;
            break;
        }
    }

    for (i = strlen(to) - 1; i >= 0; i--)
    {
        if (to[i] == ';')
        {
            to[i] = 0;
            break;
        }
    }

    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == ';')
        {
            s[i] = 0;
            break;
        }
    }

    len = strlen(s);
    lenFrom = strlen(from);
    // printf("%s\n",from);

    for (i = 0; i < len; ++i)
    {
        if (strncmp(s + i, from, lenFrom) == 0)
        {
            changed = 1;
            dx += sprintf(ans + dx, "%s", to);
            i += lenFrom - 1;
        }
        else
        {
            ans[dx] = s[i];
            dx++;
        }
    }

    if (changed)
    {
        printf("%s;", ans);
    }
    else
    {
        printf("No Replacement!");
    }
}