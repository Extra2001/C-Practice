#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

int n, T, p[30];

unsigned short res[10000000][11], nowres[11];

int cnt = 0;

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    scanf("%d", &T);
    for (int i = 1; dfs(0, i, 0); i++)
        ;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%u ", res[i][j]);
        }
        putchar('\n');
    }
    if (cnt == 0)
    {
        printf("Sorry, you failed.");
    }
    // fclose(stdin);
}

int dfs(int layer, int thiscount, int cur)
{
    int curr = cur + thiscount * p[layer];
    if (curr == T && layer == n - 1)
    {
        nowres[layer] = thiscount;
        memcpy(res[cnt], nowres, sizeof(nowres));
        cnt++;
        return 1;
    }
    if (layer >= n)
        return 0;
    if (curr >= T)
        return 0;
    nowres[layer] = thiscount;
    for (int i = 1; dfs(layer + 1, i, curr); i++)
        ;
    return 1;
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}