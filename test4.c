#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

int map[1005][1005];
long long judge[1005];

int n;
int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    IN1(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            IN1(map[i][j]);
    int flag = 1;
    // for (int i = 0; i < n; i++)
    //     if (map[i][i] != 1)
    //         flag = 0;
    long long res;
    if (flag)
    {
        judge[1] = 1;
        judge[2] = 2;
        for (int i = 3; i < n + 1; i++)
            judge[i] = ((judge[i - 1] + judge[i - 2]) * i) % 1000000007;
        res = judge[n - 1] % 1000000007;
    }
    else
        res = dfs(0);
    printf("%lld", res);
    // fclose(stdin);
}

int dfs(int row)
{
    if (row == n - 1)
    {
        int cnt = 0; //, flag = 1;
        for (int i = 0; i < n; i++)
        {
            // flag = 1;
            if (map[row][i] == 1 || judge[i] == 2)
                continue;
            // for (int j = 0; j < n; j++)
            //     if (map[j][i] == 2)
            //         flag = 0;
            // if (flag)
            cnt++;
        }
        return cnt;
    }
    int cnt = 0; //, flag = 1;
    for (int i = 0; i < n; i++)
    {
        // flag = 1;
        if (map[row][i] == 1 || judge[i] == 2)
            continue;
        // for (int j = 0; j < n; j++)
        //     if (map[j][i] == 2)
        //         flag = 0;
        // if (flag)
        // {
        judge[i] = 2;
        // map[row][i] = 2;
        cnt += dfs(row + 1);
        // map[row][i] = 0;
        judge[i] = 0;
        // }
    }
    return cnt;
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}