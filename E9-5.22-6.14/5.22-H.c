#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

int map[100][100];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int a = 2 * n - 1;
    for (int i = 0; i < n; i++)
    {
        char p = 'A';
        for (int j = 0; j < n; j++)
        {
            if (p == i + 'A')
                map[i][j] = p;
            else
                map[i][j] = p++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", map[i][j]);
        for (int j = n - 2; j >= 0; j--)
            printf("%c", map[i][j]);
        putchar('\n');
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
            printf("%c", map[i][j]);
        for (int j = n - 2; j >= 0; j--)
            printf("%c", map[i][j]);
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