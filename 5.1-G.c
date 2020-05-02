#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int a[1000015];

int comp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in2.txt", "r", stdin);
    int n;
    ll s;
    scanf("%d%lld", &n, &s);
    if (s == 0)
    {
        printf("1");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), comp);
    ll sum = 0;
    int i;
    for (i = 0; sum < s && i < n; i++)
    {
        sum += a[i];
    }
    if (sum < s)
        printf("-1");
    else
        printf("%d", i);
    // fclose(stdin);
}