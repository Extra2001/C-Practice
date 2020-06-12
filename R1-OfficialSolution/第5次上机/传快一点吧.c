#include <stdio.h>

long long m1[12][12] = {0};
long long m2[12][12] = {0};
long long m3[12][12] = {0};
long long ans1[12][12] = {0};
long long ans2[12][12] = {0};

void getMat(long long a[][12], int r, int c)
{
    int i, j;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            scanf("%lld", &a[i][j]);
        }
    }
}

void postMat(long long a[][12], int r, int c)
{
    int i, j;
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
        {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
}

void time(long long ma[][12] , int ra, int ca,
          long long mb[][12] , int rb, int cb, long long ans[][12])
{
    int i, j, k;
    for (i = 0; i < ra; ++i)
    {
        for (j = 0; j < cb; ++j)
        {
            for (k = 0; k < ca; ++k)
            {
                ans[i][j] += ma[i][k] * mb[k][j];
            }
        }
    }
}

int main()
{
    int a1, a2, a3, b1, b2, b3;
    scanf("%d %d %d %d %d %d", &a1, &b1, &a2, &b2, &a3, &b3);
    if (!(b1 == a2 && b2 == a3))
    {
        printf("Impossib1e");
        return 0;
    }
    getMat(m1, a1, b1);
    getMat(m2, a2, b2);
    getMat(m3, a3, b3);
    time(m1, a1, b1, m2, a2, b2, ans1);
    time(ans1, a1, b2, m3, a3, b3, ans2);
    postMat(ans2, a1, b3);
}