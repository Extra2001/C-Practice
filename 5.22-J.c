#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

char hao[105][10000];
char tmp[200000];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    gets(tmp);
    int n;
    sscanf(tmp, "%d", &n);
    gets(tmp);
    int len = strlen(tmp);
    int col = len / n;
    if (len % n)
        col++;
    char *p = tmp;
    for (int i = col - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (p - tmp >= len)
            {
                hao[j][i] = ' ';
                continue;
            }
            hao[j][i] = *p;
            p++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < col; j++)
        {
            putchar(hao[i][j]);
        }
        putchar('\n');
    }
    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}