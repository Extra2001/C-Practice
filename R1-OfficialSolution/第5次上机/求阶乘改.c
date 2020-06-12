#include <stdio.h>

#define N 1000000

long long ans[1000005] = {1}; // 考试中，能用long不用int
long long mid[1000005] = {1};

int main()
{
    int i, q, n;
    for (i = 1; i <= N; ++i)
    {
        mid[i] = (mid[i - 1] * i) % 1000003;
        ans[i] = (ans[i - 1] + mid[i]) % 1000003;
    }
    scanf("%d", &q);
    for (i = 0; i < q; ++i)
    {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
}