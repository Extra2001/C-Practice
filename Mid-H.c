#include <stdio.h>

int pan[21][21];

void init()
{
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            if (i == 0 || i == 20 || j == 0 || j == 20)
                pan[i][j] = -1;
}

int jDown(int i, int j)
{
    int cur = pan[i][j], flag = 1;
    for (int k = 1; k < 4; k++)
        if (pan[i + k][j] != cur)
        {
            flag = 0;
            break;
        }
    if (flag)
        if (pan[i - 1][j] == 0 || pan[i + 4][j] == 0)
            return 1;
    return 0;
}

int jRight(int i, int j)
{
    int cur = pan[i][j], flag = 1;
    for (int k = 1; k < 4; k++)
        if (pan[i][j + k] != cur)
        {
            flag = 0;
            break;
        }
    if (flag)
        if (pan[i][j - 1] == 0 || pan[i][j + 4] == 0)
            return 1;
    return 0;
}

int jDownRight(int i, int j)
{
    int cur = pan[i][j], flag = 1;
    for (int k = 1; k < 4; k++)
        if (pan[i + k][j + k] != cur)
        {
            flag = 0;
            break;
        }
    if (flag)
        if (pan[i - 1][j - 1] == 0 || pan[i + 4][j + 4] == 0)
            return 1;
    return 0;
}

int jDownLeft(int i, int j)
{
    int cur = pan[i][j], flag = 1;
    for (int k = 1; k < 4; k++)
        if (pan[i + k][j - k] != cur)
        {
            flag = 0;
            break;
        }
    if (flag)
        if (pan[i - 1][j + 1] == 0 || pan[i + 4][j - 4] == 0)
            return 1;
    return 0;
}

int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    init();
    while (~scanf("%d", &pan[1][1]))
    {
        int a, b;
        for (int j = 2; j <= 19; j++)
            scanf("%d", &pan[1][j]);
        for (int i = 2; i <= 19; i++)
            for (int j = 1; j <= 19; j++)
                scanf("%d", &pan[i][j]);
        int cur[3] = {0}, curWin = 0;
        for (int i = 1; i <= 19; i++)
            for (int j = 1; j <= 19; j++)
                if (pan[i][j])
                {
                    cur[pan[i][j]]++;
                    if (jDown(i, j) || jDownLeft(i, j) || jDownRight(i, j) || jRight(i, j))
                        curWin = pan[i][j], a = i, b = j;
                }
        if (curWin)
            printf("%d\n%d\n%d %d\n", curWin, cur[1], a, b);
        else
            printf("NO\n");
        printf("\n");
    }
}