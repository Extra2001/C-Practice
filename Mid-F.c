#include <stdio.h>

int map[305][305][2] = {0};

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    int x1, y1, x2, y2;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (; x1 <= x2; x1++)
            for (int j = y1; j <= y2; j++)
                map[x1][j][0]++, map[x1][j][1] = i;
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &x1, &y1);
        if (map[x1][y1][0])
            printf("Y %d %d\n", map[x1][y1][0], map[x1][y1][1]);
        else
            printf("N\n");
    }
}