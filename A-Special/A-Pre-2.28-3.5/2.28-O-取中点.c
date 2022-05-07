#include <math.h>
#include <stdio.h>

void QuickSort(int R[], int s, int t);
int partition(int R[], int s, int t);
int main()
{
    int n, j = 0, i = 0;
    scanf("%d\n", &n);
    int sum[n];
    for (i = 0; i < n; i++)
    {
        sum[i] = 0;
        int m = 0;
        scanf("%d\n", &m);
        int a[m];
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[j]);
        }
        if ((m & 1) == 0)
        {
            int tmp = 0;
            int tmp1 = 0;
            int b = a[m / 2];
            for (j = 0; j < m; j++)
            {
                tmp += abs(b - a[j]);
            }
            b = m / 2 - 1;
            for (j = 0; j < m; j++)
            {
                tmp1 += abs(b - a[j]);
            }
            if (tmp < tmp1)
            {
                sum[i] = tmp;
            }
            else
            {
                sum[i] = tmp1;
            }
        }
        else
        {
            int b = a[(m - 1) / 2];
            for (j = 0; j < m; j++)
            {
                sum[i] += abs(b - a[j]);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", sum[i]);
    }
    return 0;
}