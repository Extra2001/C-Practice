#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[300][300];

int get(int n, int x, int y);
void out(int n);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        memset(a, 0, sizeof(a));
        scanf("%d", &tmp);
        int nnn = 1 << tmp;
        for (int i = 0; i < nnn; i++)
        {
            for (int j = 0; j < nnn; j++)
                a[j][i] = get(tmp, i + 1, j + 1);
        }
        out(tmp);
    }
    // fclose(stdin);
}

int get(int n, int x, int y)
{
    if (n == 0)
        return 1;
    int nnn = 1 << (n - 1);
    if (x <= nnn && y <= nnn)
        return get(n - 1, y, x);
    if (x > nnn && y <= nnn)
        return 3 * nnn * nnn + get(n - 1, nnn + 1 - y, 2 * nnn - x + 1);
    if (x <= nnn && y > nnn)
        return nnn * nnn + get(n - 1, x, y - nnn);
    if (x > nnn && y > nnn)
        return 2 * nnn * nnn + get(n - 1, x - nnn, y - nnn);
}

void out(int n)
{
    int nnn = 1 << n;
    for (int i = 0; i < nnn; i++)
    {
        for (int j = 0; j < nnn; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}