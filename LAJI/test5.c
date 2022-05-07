#include <stdio.h>

long long value[100];

int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int n, i, l = 0, r = 0;
    long long cur, max = 0, sum = 0, tmp;
    while (scanf("%d", &n) != EOF)
    {
        max = sum = l = r = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &tmp);
            value[i] = tmp - sum;
            sum = tmp;
        }
        cur = max = 0;
        for (i = 1; i < n; i++)
        {
            cur += value[i];
            if (cur > max)
            {
                r = i;
                max = cur;
            }
            else if (cur < 0)
            {
                l = i;
                cur = 0;
            }
        }
        if (l == r || max <= 0)
            printf("No profit!\n");
        else
            printf("%lld %d %d\n", max, l + 1, r + 1);
    }
}
