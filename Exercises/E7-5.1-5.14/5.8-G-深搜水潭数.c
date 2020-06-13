#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[105][105];

int visited[105][105];
int N, M;
void dfs(int r, int c)
{
    visited[r][c] = 1;
    for (int k = -1; k <= 1; k++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (k == 0 && j == 0)
            {
                continue;
            }
            if (visited[r + k][c + j] == 1)
            {
                continue;
            }
            if (a[r + k][c + j] == 'W')
            {
                dfs(r + k, c + j);
            }
            else
            {
                visited[r + k][c + j] = 1;
            }
        }
    }
}
int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m;
    memset(a, '.', sizeof(a));
    scanf("%d%d", &n, &m);
    N = n;
    M = m;
    char laji[10];
    gets(laji);
    for (int i = 1; i <= n; i++)
    {
        gets(a[i] + 1);
        a[i][m + 1] = '.';
    }
    int r = 1, c = 1;
    int sum = 0;
    while (r <= n)
    {
        while (a[r][c] == '.' || visited[r][c] == 1)
        {
            visited[r][c] = 1;
            c++;
            if (c > M)
            {
                c = 0;
                r++;
            }
            if(r > n){
                goto out;
            }
        }
        sum++;
        dfs(r, c);
    }
out:;
    printf("%d", sum);
    // fclose(stdin);
}
