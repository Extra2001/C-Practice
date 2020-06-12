#include <stdio.h>
#include <stdlib.h>
struct number
{
    int value, index;
}a[105];
int cmp(const void *pa, const void *pb)
{
    struct number a = *(struct number*)pa,
                  b = *(struct number*)pb;
    if (a.value < b.value)return -1;
    else return 1;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for (i = 0;i<n;i++)
    {
        scanf("%d",&a[i].value);
        a[i].index = i + 1;
    }
    qsort(a,n,sizeof(struct number),cmp);
    for (i = 0;i<n;i++)
    {
        printf("%d%c",a[i].index, i == n-1 ? '\n' : ' ');
    }
    return 0;
}