#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long get(int n, int x, int y)
{ //（x，y）只是用来判断在哪部分
    if (n == 0)
        return 1;
    int m = 1 << (n - 1);
    if (x <= m && y <= m)
    {                            //左下角
        return get(n - 1, y, x); //返回给上一层的是此点在此层的序号
    }
    if (x > m && y <= m)
    {                                                              //右下角
        return 3LL * m * m + get(n - 1, m + 1 - y, 2 * m - x + 1); //  填空
    }
    if (x <= m && y > m)
    { //左上角
        return 1LL * m * m + get(n - 1, x, y - m);
    }
    if (x > m && y > m)
    { //右上角
        return 2LL * m * m + get(n - 1, x - m, y - m);
    }
}

int main()
{
    int n, x, y;
    scanf("%d", &n); //n为2的指数,(x,y)为顶点坐标
    printf("%lld", get(n, x, y));
    int nnn = pow(2, n);
    for (int i = 0; i < nnn; i++)
    {
        for (int j = 0; j < nnn; j++)
            get(, i + 1, j + 1);
    }
    return 0;
}