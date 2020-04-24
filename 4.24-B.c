#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[33][33];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int x, y, s, t;
    while (~scanf("%d%d%d%d", &x, &y, &s, &t))
    {
        int temp = a[x][y];
        a[x][y] = a[x + s][y + t];
        a[x + s][y + t] = temp;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // fclose(stdin);
}