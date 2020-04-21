/*时间O(n)空间O(1)的位运算(异或)解法*/
#include <stdio.h>
//jqe的卡组1, 输出唯一一个重复的整数
int n, a, k = 0;
int main(int argc, char **argv)
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n + 1; i++)
    {
        scanf("%d", &a);
        k ^= a;
    }
    for (i = 1; i <= n; i++)
        k ^= i;
    printf("%d", k);
    return 0;
}