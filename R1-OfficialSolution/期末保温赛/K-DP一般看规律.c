// 连续相同元素的个数，红黑歌合战的红组排序之后也是类似这样处理最高票的。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define max(x,y) ((x)>(y)?(x):(y))
int main()
{
    char c;
    int cnt = 0, mx = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '1')cnt++, mx = max(mx, cnt);
        else cnt = 0;
    }
    printf("%d\n", mx);
    return 0;
}