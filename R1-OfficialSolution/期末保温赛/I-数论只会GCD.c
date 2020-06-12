// 其实这题跟数论可能没啥关系
#include <stdio.h>
#include <stdlib.h>
int n, a[1000005];
int cmp(const void *a, const void *b)
{
    if (*(int*)a < *(int*)b)return -1;
    else return 1;
}

int main()
{
    int i, d, flg = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (n <= 2)printf("Yes\n");
    else
    {
        qsort(a, n, sizeof(int), cmp);
        d = a[1] - a[0];
        for (i = 2; i < n; i++)
            if (a[i] - a[i - 1] != d){flg = 0; break;}
        if (flg)
            printf("Yes\n");
        else
            printf("NO\n");
    }
    return 0;
}