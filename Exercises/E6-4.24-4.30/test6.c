#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int time[150], n, now;
char str[150][150], temp[150], num[150][10];
char check[] = "buaaycm", num5[][7] = {"23333", "66666"}, num6[][8] = {"233333", "666666", "114514"};

int isnum(char c)
{
    return (c >= '0' && c <= '9');
}

int len(char *p)
{
    char *q;
    q = p + 1;
    while (isnum(*q))
        q++;
    return q - p;
}

int cmpn(char *a, char *b, int n)
{
    while (n--)
    {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }
    return 1;
}
void cpyn(char *a, char *b, int m)
{
    while (m--)
    {
        *a = *b;
        a++;
        b++;
    }
    *a = '\0';
}

void find()
{
    if (n == 0 || time[n] + 180 < now)
    {
        printf("yaiyai!\nbuaamyc\n");
        return;
    }
    int i = n;
    printf("yaiyai!\n");
    while (i && time[i] + 180 >= now && i > n - 10)
    {
        printf("%ds:[%s] %s\n", now - time[i], num[i], str[i]);
        i--;
    }
    return;
}
int ma()
{
    freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in4.txt", "r", stdin);
    int i, hour, min, sec, l;
    char *p, *q;
    n = 0;

    while (~scanf("%d:%d:%d", &hour, &min, &sec))
    {
        now = hour * 3600 + min * 60 + sec;
        while (n && now < time[n])
            now += 24 * 3600;
        gets(temp);
        gets(temp);

        l = strlen(temp) - 1;
        while (temp[l] == '\r' || temp[l] == '\t')
        {
            temp[l] = '\0';
            l--;
        }

        if (strcmp(temp, check) == 0)
            find();

        else
        {
            l = strlen(temp) - 1;
            while (isspace(temp[l]))
            {
                temp[l] = '\0';
                l--;
            }
            p = temp;
            while (*p != '\0')
            {
                while (!isnum(*p) && *p != '\0')
                    p++;
                if (isnum(*p))
                {
                    l = len(p);
                    if (l == 5)
                    {
                        for (i = 0; i < 2; i++)
                        {
                            if (cmpn(num5[i], p, l))
                                break;
                        }
                        if (i == 2)
                        {
                            n++;
                            cpyn(num[n], p, l);
                            strcpy(str[n], temp);
                            time[n] = now;
                            break;
                        }
                    }
                    else if (l == 6)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            if (cmpn(num6[i], p, l))
                                break;
                        }
                        if (i == 3)
                        {
                            n++;
                            cpyn(num[n], p, l);
                            strcpy(str[n], temp);
                            time[n] = now;
                            break;
                        }
                    }
                    p += l;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in4.txt", "w", stdout);
    int hh = 0, mm = 0, ss = 0;
    for (int i = 0; i < 100; i++)
    {
        printf("%02d:%02d:%02d\n", hh, mm, ss);
        ss++;
        if (ss == 60)
        {
            ss = 0;
            mm++;
        }
        if (mm == 60)
        {
            hh++;
        }
        for (int j = 0; j < 100; j++)
        {
            int n = rand() % 126;
            if ((!isspace(n)) && (n != 0) && n < 127 && n > 32)
            {
                putchar(n);
            }
        }
        putchar('\n');
    }
    printf("00:02:00\nbuaaycm");
    
    fclose(stdout);
    ma();
}