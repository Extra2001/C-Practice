#include <stdio.h>

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int n, m, tmp1, tmp2;
    int min = 200000000, max = -200000000;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &tmp1);
        if (tmp1 < min)
            min = tmp1;
        if (tmp1 > max)
            max = tmp1;
    }
    printf("%lld", (long long)(max - min) * (long long)(max - min));
}