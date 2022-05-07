#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[1005];

void Reverse(int l, int r)
{
    int m = (r - l + 1) / 2;
    for (int i = 0; i < m; i++)
    {
        int temp = a[l + i];
        a[l + i] = a[r - i];
        a[r - i] = temp;
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int j = 1; j <= n; j++)
        {
            a[j] = j;
        }
        for (int j = 1; j <= m; j++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            Reverse(l, r);
        }
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    // fclose(stdin);
}