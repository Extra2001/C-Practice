#include <stdio.h>
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = n; i >= 1; i--) // 共n行，从下往上，分别是第 1 到第 n 行
    {
        for (j = 1; j <= n - i; j++) // 第i行，先打印 n-i 个空格
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++) // 第i行，接着打印 2i-1 个星
            printf("*");
        printf("\n");
    }
    return 0;
}