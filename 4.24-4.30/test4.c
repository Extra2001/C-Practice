#include <stdio.h>
#include <stdlib.h>
int main()
{
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n, i, j, x, flag, max1, max2;
    while (~(scanf("%d%d", &m, &n)))
    {
        int a[1001][2] = {0}, b[1001] = {0};
        for (i = 0; i < m; i++)
        {
            flag = 0;
            scanf("%d", &x);
            for (j = 0; j < i; j++)
            {
                if (x == a[j][0])
                {
                    a[j][1]++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                a[i][0] = x;
                a[i][1]++;
            }
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            b[x]++;
        }
        max1 = 0, j = 0;
        for (i = 0; i < m; i++)
        {
            if (a[i][1] > max1)
            {
                max1 = a[i][1];
                j = i;
            }
            else if (a[i][1] == max1)
            {
                if (a[j][0] < a[i][0])
                    j = i;
            }
        }
        printf("%d ", a[j][0]);
        //max2 = 0;
        for (i = 0; i < 1000; i++)
        {
            if (b[i] > max2)
            {
                max2 = b[i];
                j = i;
            }
            else if (b[i] == max2)
            {
                if (i > j)
                    j = i;
            }
        }
        printf("%d\n", j);
    }
    return 0;
}