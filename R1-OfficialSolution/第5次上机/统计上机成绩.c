#include <stdio.h>

double a[105][10] = {0};

int main()
{
    int m, n, i, j;
    double sum;
    scanf("%d %d", &m, &n);

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%lf", &a[i][j]);
        }
    }

    for (j = 0; j < n; ++j)
    {
        sum = 0.0;
        for (i = 0; i < m; ++i)
        {
            sum += a[i][j];
        }
        printf("%0.2f ", sum / m);
    }
    printf("\n");

    for (j = 0; j < n; ++j)
    {
        sum = 0.0;
        for (i = 0; i < m; ++i)
        {
            sum += a[i][j] >= 80;
        }
        printf("%0.2f%% ", 100.0*sum / m);
    }
      printf("\n");

    for (i = 0; i < m; ++i)
    {
        sum = 0.0;
        for (j = 0; j < n; ++j)
        {
            sum += a[i][j];
        }
        printf("%0.2f\n", sum / n);
    }
}