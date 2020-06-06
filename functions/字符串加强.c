#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}

int Trim(char *base)
{
    while (isspace(base[0]))
        base[0] = '\0';
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}

int TrimStart(char *base)
{
    while (isspace(base[0]))
        base[0] = '\0';
    return strlen(base);
}

int StartWith(char *base, char *delim)
{
    char *tmp = (char *)malloc(strlen(base) * sizeof(char));
    char *backup = tmp;
    strcpy(tmp, base);
    tmp[strlen(delim)] = '\0';
    if (strcmp(tmp, delim) == 0)
    {
        free(backup);
        return 1;
    }
    else
    {
        free(backup);
        return 0;
    }
}

int EndWith(char *base, char *delim)
{
    char *tmp = (char *)malloc(strlen(base) * sizeof(char));
    char *backup = tmp;
    strcpy(tmp, base);
    tmp += strlen(base) - strlen(delim);
    if (strcmp(tmp, delim) == 0)
    {
        free(backup);
        return 1;
    }
    else
    {
        free(backup);
        return 0;
    }
}

int isHuiwen(char *str, int len)
{
    char *s = (char *)malloc(sizeof(char) * strlen(str));
    strcpy(s, str);
    s[len] = '\0';
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - i - 1])
            return 0;
    return 1;
}

void sectionReverse(char *str, int l, int r)
{
    int len = r - l + 1;
    for (int i = 0; i < len / 2; i++)
    {
        int tmp = str[l + i];
        str[l + i] = str[r - i];
        str[r - i] = tmp;
    }
}