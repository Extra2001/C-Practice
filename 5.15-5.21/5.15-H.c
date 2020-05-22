

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

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
                sum += (matrix1[i][k] * matrix2[k][j]) % 1000000007;
            }
            res[i][j] = sum % 1000000007;
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

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m1[i][j]);
    Copy(m1, m2);
    for (int i = 1; i < k; i++)
    {
        MatrixMultiply(m1, m2, res, n, n, n);
        Copy(res, m2);
    }
    OutPut(m2, n, n);
    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}