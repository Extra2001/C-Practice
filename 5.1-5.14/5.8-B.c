#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[105][105];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n, k, l;
    scanf("%d%d", &m, &n);
    gets(a[1]);
    for (int i = 0; i < m; i++)
    {
        gets(a[i]);
    }
    scanf("%d%d", &k, &l);
    puts(a[k - 1]);
    int row = 0, col = 0, sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            col++;
            sum++;
            if (sum == l - 1)
            {
                goto la;
            }
        }
        row++;
        col = 0;
    }
la:;
    if (col == 0)
    {
        col = n;
    }
    char *p = &a[row][col];
    printf("%s", p);
    for (int i = row + 1; i < m; i++)
    {
        printf("%s", a[i]);
    }
    // fclose(stdin);
}