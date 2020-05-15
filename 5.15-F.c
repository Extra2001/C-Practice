#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

char ori[1000];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    while (gets(ori) != NULL)
    {
        int wei;
        sscanf(ori, "%*lf%d", &wei);
        *(strchr(ori, ' ')) = '\0';
        int isfu = 0;
        int flag = 0;
        if (ori[0] == '-')
        {
            isfu = 1;
            char tmp[1000];
            strcpy(tmp, ori + 1);
            strcpy(ori, tmp);
        }
        char *p = strchr(ori, '.');
        p += wei;
        if ((*(p + 1)) - 48 == 5)
        {
            char *u = ori + strlen(ori) - 1;
            int flag2 = 0;
            while (u != p + 1)
            {
                if (*u != '0')
                {
                    flag2 = 1;
                    break;
                }
                u--;
            }
            if (*p == '.')
            {
                p--;
            }
            if (flag2)
            {
                int i;
                for (i = 0; p - i != ori; i++)
                {
                    if ((*(p - i)) == '9')
                        *(p - i) = '0';
                    else if ((*(p - i)) == '.')
                        continue;
                    else
                        break;
                }
                if (ori[0] == '9' && p - i == ori)
                {
                    char tmp[1000];
                    *(p - i) = '0';
                    strcpy(tmp, ori);
                    strcpy(ori + 1, tmp);
                    ori[0] = '0';
                    flag = 1;
                }
                (*(p - i))++;
            }
            else
            {
                if ((((*p) - 48) & 1))
                {
                    int i;
                    for (i = 0; p - i != ori; i++)
                    {
                        if ((*(p - i)) == '9')
                            *(p - i) = '0';
                        else if ((*(p - i)) == '.')
                            continue;
                        else
                            break;
                    }
                    if (ori[0] == '9' && p - i == ori)
                    {
                        char tmp[1000];
                        *(p - i) = '0';
                        strcpy(tmp, ori);
                        strcpy(ori + 1, tmp);
                        ori[0] = '0';
                        flag = 1;
                    }
                    (*(p - i))++;
                }
            }
        }
        else if ((*(p + 1)) - 48 > 5)
        {
            int i;
            for (i = 0; p - i != ori; i++)
            {
                if ((*(p - i)) == '9')
                    *(p - i) = '0';
                else if ((*(p - i)) == '.')
                    continue;
                else
                    break;
            }
            if (ori[0] == '9' && p - i == ori)
            {
                char tmp[1000];
                *(p - i) = '0';
                strcpy(tmp, ori);
                strcpy(ori + 1, tmp);
                ori[0] = '0';
                flag = 1;
            }
            (*(p - i))++;
        }
        if (flag)
            *(p + 2) = '\0';
        else
            *(p + 1) = '\0';
        if (isfu)
        {
            printf("-");
        }
        if (ori[strlen(ori) - 1] == '.')
            ori[strlen(ori) - 1] = '\0';
        puts(ori);
    }

    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}