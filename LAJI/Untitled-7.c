

#include <stdio.h>
int main()
{
    char c[30];
    int i = 0;
    int isfu = 0;
    while ((c[i] = getchar()) != '\n')
    {
        if (c[i] == '-')
            isfu = 1;
        i++;
    }
    if (i > 0)
    {
        i--;
        while (c[i] == '0')
        {
            i--;
        }
        if (i > 0)
        {
            if (isfu == 1)
                printf("-");
            if (c[i] == '.')
                printf("0");
            for (; i >= 0; i--)
            {
                if (c[i] != '-')
                    printf("%c", c[i]);
            }
        }
        else
            printf("%c", c[0]);
    }

    return 0;
}