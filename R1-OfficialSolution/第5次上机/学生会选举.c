#include <stdio.h>

int main()
{
    int i, n = 0, t, a[1005] = {0}, j;
    while (scanf("%d", a + n) > 0)
    {
        n++;
    }

    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
}