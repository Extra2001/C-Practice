#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

char hao[200015];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    gets(hao);
    int len = strlen(hao);
    int count = 0, max = 0;
    for (int i = 0; i < len; i++)
    {
        if (hao[i] == '1')
            count++;
        else
        {
            if (count > max)
                max = count;
            count = 0;
        }
    }
    if (count > max)
        max = count;
    printf("%d", max);
    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}