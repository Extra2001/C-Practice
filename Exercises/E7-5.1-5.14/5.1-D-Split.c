#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10005

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int split(char *base, char *seperator, char *(**res));
int TrimEndR(char *base);

char s[10005];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    char sep[25];
    scanf("%s", s);
    scanf("%s", sep);
    char **tmp;
    int n = split(s, sep, &tmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s;\n", tmp[i]);
    }
    // fclose(stdin);
}

int split(char *base, char *seperator, char *(**res))
{
    *res = malloc(sizeof(char *) * MAX);
    int cnt = 0;
    char *find, *cur = base;
    while (find = strstr(cur, seperator))
    {
        char *toAdd = (char *)malloc(sizeof(char) * (find - cur + 1));
        memset(toAdd, 0, sizeof(toAdd));
        if (find - cur != 0)
            memcpy(toAdd, cur, find - cur);
        (*res)[cnt++] = toAdd;
        cur = find + strlen(seperator);
    }
    char *toAdd = (char *)malloc(sizeof(char) * (strlen(cur) + 1));
    memset(toAdd, 0, sizeof(toAdd));
    if (find - cur != 0)
        memcpy(toAdd, cur, strlen(cur));
    (*res)[cnt++] = toAdd;
    return cnt;
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}