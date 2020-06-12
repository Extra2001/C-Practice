#include <stdio.h>

int a[1006] = {0}, N;

int find(int n)
{
    int cnt = 0, i = n;
    while (i != N)
    {
        cnt++;
        i = a[i];
        if (cnt > N)
        {
            break;
        }
    }

    return cnt;
}

int main()
{
    int i, ans;
    while (scanf("%d", &N) > 0)
    {
        ans = 0;
        for (i = 1; i <= N; i++)
        {
            scanf("%d", a + i);
        }
        for (i = 1; i < N; i++)
        {
            if (find(i) > ans)
            {
                ans = find(i);
            }
        }
        if (ans >= N)
        {
            printf("No solution!\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
}