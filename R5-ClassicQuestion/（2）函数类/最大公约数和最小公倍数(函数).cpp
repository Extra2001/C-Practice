#include <stdio.h>
void F(void)
{
    int i, m, n, t;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        if (m > n)
        {
            t = m;
            m = n;
            n = t;
        }
        for (i = m; i > 0; i--)
            if (m % i == 0 & n % i == 0)
            {
                printf("最大公约数为：%d ", i);
                break;
            }
        for (i = 1; i <= m; i++)
            if (n * i % m == 0)
            {
                printf("\n");
                printf("最小公倍数为：%d\n", n * i);
                break;
            }
    }
}

int main()
{
    printf("请输入两个数：");
    F();
}
