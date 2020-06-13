#include <stdio.h>
double move4(int);

int a[105] = {0};
int main()
{
    move4(101);
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", a[i + 1]);
    }
}

double move3(int n)
{
    return pow(2, n) - 1;
}

double move4(int n)
{
    if (n == 1)
    { //Base
        return 1;
    }
    if (a[n] != 0)
    {
        return a[n];
    }
    double step = 10000000; //设置的大一点以便更新
    for (int x = 1; x < n; x++)
    {
        double temp = 2.0 * move4(x) + (double)move3(n - x);
        if (temp < step)
        {
            step = temp;
        }
    }
    a[n] = step;
    return step;
}