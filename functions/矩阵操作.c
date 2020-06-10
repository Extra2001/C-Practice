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

//以下为借鉴他人的矩阵操作代码，可能稍稍有一点点问题

typedef struct
{
    /* 维度 */
    int rows;
    int cols;
    /* 内容 */
    double **data;
} Matrix;

/* 为矩阵分配初始空间 */
Matrix alloc_matrix(int rows, int cols)
{
    Matrix m;
    int i;
    int j;
    m.rows = rows;
    m.cols = cols;
    m.data = (double **)malloc(sizeof(double *) * m.rows);
    for (i = 0; i < m.rows; ++i)
    {
        m.data[i] = (double *)malloc(sizeof(double) * m.cols);
        for (j = 0; j < m.cols; ++j)
        {
            m.data[i][j] = 0.0;
        }
    }
    return m;
}
/* 释放空间 */
void free_matrix(Matrix m)
{
    int i;
    for (i = 0; i < m.rows; ++i)
    {
        free(m.data[i]);
    }
    free(m.data);
}
/* 转换为单元矩阵 */
void set_identity_matrix(Matrix m)
{
    int i;
    int j;
    for (i = 0; i < m.rows; ++i)
    {
        for (j = 0; j < m.cols; ++j)
        {
            if (i == j)
            {
                m.data[i][j] = 1.0;
            }
            else
            {
                m.data[i][j] = 0.0;
            }
        }
    }
}
/* 复制矩阵 */
void copy_matrix(Matrix source, Matrix destination)
{
    int i;
    int j;
    for (i = 0; i < source.rows; ++i)
    {
        for (j = 0; j < source.cols; ++j)
        {
            destination.data[i][j] = source.data[i][j];
        }
    }
}
/* 打印矩阵 */
void print_matrix(char *format, Matrix m)
{
    int i;
    int j;
    for (i = 0; i < m.rows; ++i)
    {
        for (j = 0; j < m.cols; ++j)
        {
            if (j > 0)
            {
                printf(" ");
            }
            printf(format, m.data[i][j]);
        }
        printf("\n");
    }
}
/* 矩阵相加 */
void add_matrix(Matrix a, Matrix b, Matrix c)
{
    int i;
    int j;
    for (i = 0; i < a.rows; ++i)
    {
        for (j = 0; j < a.cols; ++j)
        {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
}
/* 矩阵相减 */
void subtract_matrix(Matrix a, Matrix b, Matrix c)
{
    int i;
    int j;
    for (i = 0; i < a.rows; ++i)
    {
        for (j = 0; j < a.cols; ++j)
        {
            c.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
}
/* 用单元矩阵减去该矩阵 */
void subtract_from_identity_matrix(Matrix a)
{
    int i;
    int j;
    for (i = 0; i < a.rows; ++i)
    {
        for (j = 0; j < a.cols; ++j)
        {
            if (i == j)
            {
                a.data[i][j] = 1.0 - a.data[i][j];
            }
            else
            {
                a.data[i][j] = 0.0 - a.data[i][j];
            }
        }
    }
}
/* 矩阵相乘 */
void multiply_matrix(Matrix a, Matrix b, Matrix res)
{
    int i;
    int j;
    int k;
    for (i = 0; i < res.rows; ++i)
    {
        for (j = 0; j < res.cols; ++j)
        {
            /* Calculate element c.data[i][j] via a dot product of one row of a with one column of b */
            res.data[i][j] = 0.0;
            for (k = 0; k < a.cols; ++k)
            {
                res.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
}

/* 乘以一个矩阵的转置矩阵. */
void multiply_by_transpose_matrix(Matrix a, Matrix b, Matrix res)
{
    int i;
    int j;
    int k;
    for (i = 0; i < res.rows; ++i)
    {
        for (j = 0; j < res.cols; ++j)
        {
            /* Calculate element c.data[i][j] via a dot product of one row of a with one row of b */
            res.data[i][j] = 0.0;
            for (k = 0; k < a.cols; ++k)
            {
                res.data[i][j] += a.data[i][k] * b.data[j][k];
            }
        }
    }
}
/* 矩阵转置 */
void transpose_matrix(Matrix input, Matrix output)
{
    int i;
    int j;
    //int k;
    for (i = 0; i < input.rows; ++i)
    {
        for (j = 0; j < input.cols; ++j)
        {
            output.data[j][i] = input.data[i][j];
        }
    }
}
/* 两矩阵是否相等 */
int equal_matrix(Matrix a, Matrix b, double tolerance)
{
    int i;
    int j;
    //int k;
    for (i = 0; i < a.rows; ++i)
    {
        for (j = 0; j < a.cols; ++j)
        {
            if (abs(a.data[i][j] - b.data[i][j]) > tolerance)
            {
                return 0;
            }
        }
    }
    return 1;
}
/* 矩阵乘以一个系数 */
void scale_matrix(Matrix m, double scalar)
{
    int i;
    int j;
    for (i = 0; i < m.rows; ++i)
    {
        for (j = 0; j < m.cols; ++j)
        {
            m.data[i][j] *= scalar;
        }
    }
}
/* 交换矩阵的两行 */
void swap_rows(Matrix m, int r1, int r2)
{
    double *tmp;
    tmp = m.data[r1];
    m.data[r1] = m.data[r2];
    m.data[r2] = tmp;
}
/* 矩阵某行乘以一个系数 */
void scale_row(Matrix m, int r, double scalar)
{
    int i;
    for (i = 0; i < m.cols; ++i)
    {
        m.data[r][i] *= scalar;
    }
}

/* Add scalar * row r2 to row r1. */
void shear_row(Matrix m, int r1, int r2, double scalar)
{
    int i;
    for (i = 0; i < m.cols; ++i)
    {
        m.data[r1][i] += scalar * m.data[r2][i];
    }
}

/* 矩阵的求逆(借鉴他人) */
/* Uses Gauss-Jordan elimination.

    The elimination procedure works by applying elementary row
    the identity matrix.
    Simultaneously, we apply the same elementary row operations to a
    separate identity matrix to produce the inverse matrix.
    If this makes no sense, read wikipedia on Gauss-Jordan elimination.

    This is not the fastest way to invert matrices, so this is quite
    possibly the bottleneck. */
int destructive_invert_matrix(Matrix input, Matrix output)
{
    int i;
    int j;
    int r;
    double scalar;
    double shear_needed;
    set_identity_matrix(output);
    /* Convert input to the identity matrix via elementary row operations.
    The ith pass through this loop turns the element at i,i to a 1
     and turns all other elements in column i to a 0. */
    for (i = 0; i < input.rows; ++i)
    {
        if (fabs(input.data[i][i]) < __DBL_EPSILON__)
        {
            /* We must swap rows to get a nonzero diagonal element. */
            for (r = i + 1; r < input.rows; ++r)
            {
                if (fabs(input.data[r][i]) > __DBL_EPSILON__)
                {
                    break;
                }
            }
            if (r == input.rows)
            {
                /* Every remaining element in this column is zero, so this matrix cannot be inverted. */
                return 0;
            }
            swap_rows(input, i, r);
            swap_rows(output, i, r);
        }
        /* Scale this row to ensure a 1 along the diagonal. We might need to worry about overflow from a huge scalar here. */
        scalar = 1.0 / input.data[i][i];
        scale_row(input, i, scalar);
        scale_row(output, i, scalar);
        /* Zero out the other elements in this column. */
        for (j = 0; j < input.rows; ++j)
        {
            if (i == j)
            {
                continue;
            }
            shear_needed = -input.data[j][i];
            shear_row(input, j, i, shear_needed);
            shear_row(output, j, i, shear_needed);
        }
    }

    return 1;
}

//操作函数

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    IN1(n);
    Matrix ma = alloc_matrix(n, n), mares = alloc_matrix(n, n);
    Matrix b = alloc_matrix(n, 1), cres = alloc_matrix(n, 1);
    double tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%lf", &ma.data[i][j]);
        scanf("%lf", &b.data[i][0]);
    }
    destructive_invert_matrix(ma, mares);
    multiply_matrix(mares, b, cres);
    print_matrix("%.6lf", cres);
    // fclose(stdin);
}