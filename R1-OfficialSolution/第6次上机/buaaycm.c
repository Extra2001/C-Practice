#include <stdio.h>
#include <string.h>

char dateStr[200] = {0};
char sayStr[200];
int top = 0;
int time[200] = {0};
char say[200][150] = {0};
char car[200][10] = {0};

int isNum(char c)
{
    return c <= '9' && c >= '0';
}

int notGood(int i, int n)
{
    if (n == 5)
    {
        if (strncmp(sayStr + i, "23333", n) == 0 || strncmp(sayStr + i, "66666", n) == 0)
        {
            return 1;
        }
    }
    else if (n == 6)
    {
        if (strncmp(sayStr + i, "233333", n) == 0 || strncmp(sayStr + i, "666666", n) == 0 || strncmp(sayStr + i, "114514", n) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int numLen(int i)
{
    int n = 0;
    while (isNum(sayStr[i + n]))
    {
        n++;
    }
    return n;
}

int main()
{
    int h, m, s, i, len, j, finish, t, ok;
    while (gets(dateStr) != NULL)
    {
        gets(sayStr);
        len=strlen(sayStr);
        if(sayStr[len-1]=='\r'){
            sayStr[len-1]=0;
            len--;
        }
        sscanf(dateStr, "%d:%d:%d", &h, &m, &s);
        t = h * 3600 + m * 60 + s;
        finish = 0;
        if (strcmp(sayStr, "buaaycm") == 0)
        {
            printf("yaiyai!\n");
            for (i = top - 1; i >= 0&& i>=top-10; --i)
            {
                if (time[i] + 180 >= t)
                {
                    printf("%ds:[%s] %s\n", t - time[i], car[i], say[i]);
                    finish = 1;
                }
                else
                {
                    break;
                }
            }
            if (!finish)
            {
                printf("buaamyc\n");
            }
            continue;
        }

        // len = strlen(sayStr);
        for (i = 0; i < len && (!finish); ++i)
        {

            j = numLen(i);
            if ((j == 5 || j == 6) && (!notGood(i, j)))
            {
                time[top] = t;
                strcpy(say[top], sayStr);
                strncpy(car[top], sayStr + i, j);
                top++;
                break;
            }
            else if (j >= 1)
            {
                i += j - 1;
            }
        }
    }
}