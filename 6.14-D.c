#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

int a[1005][1005];
int res[1005][2];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, d, m;
    IN3(n, d, m);
    int tmpx, tmpy;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tmpx, &tmpy);
        a[tmpx][tmpy] = 1;
    }
    int max = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            if (a[i][j] == 1)
                continue;
            for (int k = -1 * d; k <= d; k++)
            {
                if (i + k < 1 || i + k > n)
                    continue;
                for (int l = -1 * d; l <= d; l++)
                {
                    if (j + l < 1 || j + l > n)
                        continue;
                    if (a[i + k][j + l] == 1)
                    {
                        cnt++;
                    }
                }
            }
            if (cnt >= max)
                max = cnt;
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            if (a[i][j] == 1)
                continue;
            for (int k = -d; k <= d; k++)
            {
                if (i + k < 1 || i + k > n)
                    continue;
                for (int l = -d; l <= d; l++)
                {
                    if (j + l < 1 || l + j > n)
                        continue;
                    if (a[i + k][j + l] == 1)
                    {
                        cnt++;
                    }
                }
            }
            if (cnt == max)
            {
                res[count][0] = i;
                res[count++][1] = j;
            }
        }
    }
    printf("%d\n", max);
    for (int i = 0; i < count; i++)
    {
        printf("%d %d\n", res[i][0], res[i][1]);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}