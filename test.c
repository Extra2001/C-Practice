
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int m, n;
int a[20100] = {0}, b[10010] = {0};
//m行n列
void mergearray(int *arr1, int cnt1, int *arr2, int cnt2)
{
    //arr1和arr2降序 合并arr2到arr1
    int p1 = cnt1 - 1, p2 = cnt2 - 1, p = cnt1 + cnt2 - 1;
    while (p >= 0)
    {
        if ((p2 <= -1 && p1 >= 0) || (p1 > -1 && arr1[p1] <= arr2[p2]))
        {
            arr1[p] = arr1[p1];
            p1--;
        }
        else
        {
            arr1[p] = arr2[p2];
            p2--;
        }
        p--;
    }
}
int cbjsearch(int *arr, int cnt, int tar)
{ //arr按降序
    int l = 0, r = cnt - 1, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (arr[m] < tar)
        {
            r = m - 1;
        }
        else if (arr[m] > tar)
        {
            l = m + 1;
        }
        else
        {
            int p = arr[m];
            while (m >= 0 && arr[m] == p)
                m--;
            return m;
        }
    }
    return -3;
}
int main()
{
    freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m, k, i, t, s;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (i = n - 1; i >= 0; i--)
        {
            scanf("%d", a + i);
        }
        for (i = 0; i < m; i++)
        {
            scanf("%d", b + i);
        }
        mergearray(a, n, b, m);
        for (i = 0; i < k; i++)
        {
            scanf("%d", &t);
            s = cbjsearch(a, m + n, t);
            printf("%d ", s == -3 ? -1 : s + 2);
        }
        putchar('\n');
    }
    return 0;
}
