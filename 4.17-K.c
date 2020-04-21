#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long matrix1[11][11];
long long matrix2[11][11];
long long matrix3[11][11];
long long res1[11][11];
long long res2[11][11];

int a1, a2, a3, b1, b2, b3;

void read()
{
    scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
    for (int i = 0; i < a1; i++)
        for (int j = 0; j < b1; j++)
            scanf("%lld", &matrix1[i][j]);
    for (int i = 0; i < a2; i++)
        for (int j = 0; j < b2; j++)
            scanf("%lld", &matrix2[i][j]);
    for (int i = 0; i < a3; i++)
        for (int j = 0; j < b3; j++)
            scanf("%lld", &matrix3[i][j]);
}

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
                sum += matrix1[i][k] * matrix2[k][j];
            }
            res[i][j] = sum;
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

    read();

    MatrixMultiply(matrix1, matrix2, res1, a1, b1, b2);
    MatrixMultiply(res1, matrix3, res2, a1, b2, b3);

    OutPut(res2, a1, b3);

    // fclose(stdin);
}