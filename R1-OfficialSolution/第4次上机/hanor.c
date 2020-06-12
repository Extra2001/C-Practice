#include <stdio.h>
int F3(int);
int F4(int);
int f3[105] = {0}, f4[105] = {0};

// 一个是TLE
// 数据溢出的坑 

int main()
{
    int n;
    while (scanf("%d", &n) > 0)
    {
        printf("%d\n", F4(n));
    }
    return 0;
}
int F3(int N)
{
    if (f3[N])
    {
        return f3[N]; //记忆递归 // 不会的是弟弟
    }
    if (N == 1)
        return 1;

    f3[N] = 2 * F3(N - 1) + 1;
    if(f3[N]<0 || f3[N]>9999999){   // 防止数据溢出 
        f3[N]=9999999;
    }
    return f3[N];
}
int F4(int N1)
{
    int i = 1, F4min;

    if (f4[N1])
    {
        return f4[N1];
    }

    F4min = F3(N1);
    while (i < N1)
    {
        if (2 * F4(i) + F3(N1 - i) < F4min)
        {
            F4min = 2 * F4(i) + F3(N1 - i);
        }
        i++;
    }

    f4[N1] = F4min;
    return F4min;
}
