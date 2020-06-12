#include <stdio.h>

char a[105][105];
int gone[105][105] = {0};
int gone2[105][105] = {0};
int n;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int DX[] = {0, 1, 0, -1};
int DY[] = {1, 0, -1, 0};

int out(int x, int y)
{
    if (x >= n || x < 0 || y >= n || y < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", a[i]);
    }
    k = 0, i = 0, j = 0;
    ;
    while (1)
    {
        // putchar(a[i][j]);
        if (a[i][j] >= 'a' && a[i][j] <= 'z')
        {
            putchar(a[i][j]);
        }
        gone[i][j] = 1;
        if (gone[i + dy[k]][j + dx[k]] || out(i + dy[k], j + dx[k]))
        {
            k = (k + 1) % 4;
            if (gone[i + dy[k]][j + dx[k]] || out(i + dy[k], j + dx[k]))
            {
                break;
            }
        }
        i += dy[k];
        j += dx[k];
    }

    printf("\n");
    for (k = 0, i = 0, j = 0; !(gone2[i][j] || out(i, j)); i += DY[k], j += DX[k])
    {
        // putchar(a[i][j]);
        if (a[i][j] >= 'A' && a[i][j] <= 'Z')
        {
            putchar(a[i][j]);
        }
        gone2[i][j] = 1;
        if (gone2[i + DY[k]][j + DX[k]] || out(i + DY[k], j + DX[k]))
        {
            k = (k + 1) % 4;
        }
    }
}