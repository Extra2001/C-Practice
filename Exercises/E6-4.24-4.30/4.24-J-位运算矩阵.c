#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long m1[11][11];
long long m2[11][11];
long long res[11][11];

void MatrixMultiply(long long matrix1[][11], long long matrix2[][11], long long res[][11], int a1, int b1, int b2)
{
    memset(res, 0, sizeof(long long) * 11 * 11);
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < b2; j++)
        {
            long long sum = 0;
            for (int k = 0; k < b1; k++)
            {
                sum += (matrix1[i][k] * matrix2[k][j]) % 1000003;
            }
            res[i][j] = sum % 1000003;
        }
    }
}

void Copy(long long from[][11], long long to[][11])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            to[i][j] = from[i][j];
        }
    }
}

void OutPut(long long matrix[][11], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%lld ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    char a[10];
    int flag = 0;
    while (gets(a) != NULL)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (flag)
                {
                    m2[i][6 - j] = ((a[i] >> j) & 1);
                }
                else
                {
                    m1[i][6 - j] = ((a[i] >> j) & 1);
                }
            }
        }
        if (flag)
        {
            MatrixMultiply(m1, m2, res, 7, 7, 7);
            Copy(res, m1);
        }
        flag = 1;
    }
    OutPut(m1, 7, 7);

    //fclose(stdin);
}