#include <stdio.h>

// int L[100005];
// int R[100005];
int N[10100];
int top = 0;
int *end=N+10099;
int *this;
int main()
{
    int n, d1, h1, m1, d2, h2, m2, tl, tr, max, i,sum=0;
    while (scanf("%d %d %d:%d %d %d:%d", &n, &d1, &h1, &m1, &d2, &h2, &m2) > 0)
    {
        tl = d1 * 1440 + h1 * 60 + m1;
        tr = d2 * 1440 + h2 * 60 + m2;
        N[tl]+=n;
        N[tr+1]-=n;
    }
    max = 0;
    for (this = N; this<= end; ++this)
    {
        sum+=*this;
        if (sum> max)
        {
            max = sum;
        }
    }
    printf("%d", max);
}