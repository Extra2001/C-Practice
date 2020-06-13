#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[1000015];
int b[1000015];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n;
    while (~scanf("%d%d", &m, &n))
    {
        int mid, isOu = 0;
        int sum = m + n;
        mid = sum / 2;
        if ((sum & 1) == 0)
            isOu = 1;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }
        int i = 0, j = 0, k = 0;
        double last = 0, cur = 0;
        for (k = 0; k <= mid; k++)
        {
            if (i < m && j < n)
            {
                if (a[i] > b[j])
                {
                    last = cur;
                    cur = b[j];
                    j++;
                    continue;
                }
                else
                {
                    last = cur;
                    cur = a[i];
                    i++;
                    continue;
                }
            }
            if (j < n)
            {
                last = cur;
                cur = b[j];
                j++;
                continue;
            }
            if (i < m)
            {
                last = cur;
                cur = a[i];
                i++;
                continue;
            }
        }
        if (isOu)
        {
            printf("%.1lf\n", (cur + last) / 2.0);
        }
        else
        {
            printf("%.1lf\n", (double)cur);
        }
    }
    // fclose(stdin);
}