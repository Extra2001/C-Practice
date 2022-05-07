#include <stdio.h>
int fact(int m)
{
    int re = 1;
    for (; m > 0; m--)
    {
        re = re * m;
    }
    return re;
}

int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int n, i;
    unsigned long long b[10020];
    double a[10020][2];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf%lf", &a[i][0], &a[i][1]);
    }
    for (i = 0; i < n; i++)
    {
        if (a[i][0] < a[i][1])
        {
            printf("You're kidding me!\n");
        }
        else
        {
            b[i] = ((double)fact(a[i][0]) / (fact(a[i][1]) * fact(a[i][0] - a[i][1])) + 1e-8);
            printf("%llu\n", b[i]);
        }
    }
    return 0;
}