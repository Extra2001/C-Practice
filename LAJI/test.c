#include <math.h>
#include <stdio.h>
int main()
{
    int m, s, t, n, a, t1, t2;
    scanf("%d %d %d %d", &m, &s, &t, &n);
    a = (n % (2 * (m - 1))) + 1;
    if (a == m)
    {
        t1 = m - s;
        if (s < t)
        {
            t2 = s - 1 + t - 1;
        }
        else
        {
            t2 = t - s;
        }
    }
    else if (a < m)
    {
        if (s < a)
        {
            t1 = m - a + m - s;
        }
        else
        {
            t1 = m - s;
        }
        if (s < t)
        {
            t2 = s - 1 + t - 1;
        }
        else
        {
            t2 = t - s;
        }
    }
    else
    {
        if (s > 2 * m - a)
        {
            t1 = 2 * m - a + s - 2;
        }
        else
        {
            t1 = 2 * m - a - s;
        }
        if (s < t)
        {
            t2 = s - 1 + t - 1;
        }
        else
        {
            t2 = t - s;
        }
    }
    printf("%d", n + t1 + t2);
    return 0;
}