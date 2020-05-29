#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

//矩阵1：a1*b1, a2*b2

long long m1[55][55];
long long m2[55][55];
long long res[55][55];

void MatrixMultiply(long long matrix1[][55], long long matrix2[][55], long long res[][55], int a1, int b1, int b2)
{
    memset(res, 0, sizeof(long long) * 55 * 55);
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < b2; j++)
        {
            long long sum = 0;
            for (int k = 0; k < b1; k++)
            {
                sum += (matrix1[i][k] * matrix2[k][j]) % MOD;
            }
            res[i][j] = sum % MOD;
        }
    }
}

void Copy(long long from[][55], long long to[][55])
{
    for (int i = 0; i < 55; i++)
    {
        for (int j = 0; j < 55; j++)
        {
            to[i][j] = from[i][j];
        }
    }
}

void OutPut(long long matrix[][55], int a, int b)
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