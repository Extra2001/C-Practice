#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lol long long

const int cx[4] = {1, -1, 0, 0};
const int cy[4] = {0, 0, 1, -1};
int n, vis[222][222], r, sm;
lol d, rb, rw;
char s[222][222];

int dfs(int x, int y)
{
    vis[x][y] = 1;
    if (s[x][y] != 'E')
        return s[x][y] == 'B' ? 1 : 2;
    ++sm;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (x + cx[i] >= 1 && x + cx[i] <= n && y + cy[i] >= 1 && y + cy[i] <= n && !vis[x + cx[i]][y + cy[i]])
            {
                int t = dfs(x + cx[i], y + cy[i]);
                if (r == 4)
                    continue;
                if (!r)
                    r = t;
                else if (r == t + 1 || r == t - 1)
                    r = 4;
            }
        }
    }
    return r;
}

int main()
{
    scanf("%d%lld\n", &n, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] != 'E')
            {
                if (s[i][j] == 'B')
                    rb++;
                else
                    rw++;
                continue;
            }
            if (!vis[i][j])
            {
                r = 0;
                sm = 0;
                for (int ii = 1; ii <= n; ii++)
                    for (int jj = 1; jj <= n; jj++)
                        if (s[ii][jj] != 'E')
                            vis[ii][jj] = 0;
                int t = dfs(i, j);
                if (t == 1)
                    rb += sm;
                else if (t == 2)
                    rw += sm;
            }
        }
    }
    printf("%lld\n", rb - rw - d * 2);
    return 0;
}