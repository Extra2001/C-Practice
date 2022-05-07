#include <stdio.h>
#define length 110

int boomnum(int r, int l, int n, int m);
char chart[length][length];

int main()
{
    int n, m, i, j;

    scanf("%d%d", &n, &m);
    getchar();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            chart[i][j] = getchar();
        getchar();
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", boomnum(i, j, n, m));
        printf("\n");
    }

    return 0;
}

int boomnum(int r, int l, int n, int m)
{
    int i, j, sum = 0;
    for (i = r - 1; i <= r + 1; i++)
    {
        for (j = l - 1; j <= l + 1; j++)
        {
            if (i >= 0 && j >= 0 && i <= n && j <= m && chart[i][j] == 'Y')
                sum++;
        }
    }
    return sum;
}
