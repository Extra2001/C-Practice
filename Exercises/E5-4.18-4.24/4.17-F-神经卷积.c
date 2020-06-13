#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pic[720][960];
int pro[720][960];
int core[13][13];

int main()
{
    int h, w, m;
    scanf("%d%d%d", &h, &w, &m);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf("%d", &pic[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &core[i][j]);
        }
    }
    int htimes = h - m + 1, wtimes = w - m + 1;
    for (int k = 0; k < htimes; k++)
    {
        for (int l = 0; l < wtimes; l++)
        {
            int sum = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    sum += pic[k + i][l + j] * core[i][j];
                }
            }
            pro[k][l] = sum;
        }
    }
    for (int i = 0; i < htimes; i++)
    {
        for (int j = 0; j < wtimes; j++)
        {
            printf("%d ", pro[i][j]);
        }
        printf("\n");
    }
}