#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[105];
int main()
{
    int n,i,j;
    int cnt = 0;
    scanf("%d",&n);
    for (i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n - 1; i++)
        for (j = i + 1; j <= n; j++)
            if (a[i] > a[j])cnt++;
    printf("%d\n", cnt);
    return 0;
}