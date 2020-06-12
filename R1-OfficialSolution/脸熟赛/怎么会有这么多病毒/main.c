#include <stdio.h>

#define MAX 300005

int a[MAX]={0};
int b[MAX]={0};
int c[MAX]={0};
int s[MAX]={0};

int main()
{
    int m, n, i;
    int count = 0;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d %d %d", a+i, b+i, c+i);
        s[a[i]+b[i]+c[i]]=i;
    }
    for (i = 300004; i >= 0; i--)
    {

        if (s[i])
        {
            printf("%d %d %d\n", a[s[i]], b[s[i]], c[s[i]]);
            count++;
        }
        if (count >= m || count >= n)
        {
            break;
        }
    }
    return 0;
}