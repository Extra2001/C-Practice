#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);
#define OUT1(a) printf("%d", a);
#define OUT2(a, b) printf("%d%d", a, b);
#define OUT3(a, b, c) printf("%d%d%d", a, b, c);
#define OS(c) printf("%s", c);

void LoopOutInt(int a[], int n);
void QuickSort(int a[], int n, int flag);
int CompareFromLowToHigh(const void *a, const void *b);
int CompareFromHighToLow(const void *a, const void *b);
void BubbleSort(int a[], int n, int flag);
int C(int n, int m);
int getFactorial(int n);
int SetBit(int Bit, int Number, int ToSet);
int LoopBitLeft(int a, int n);

int StartWith(char *base, char *delim)
{
    char *tmp = (char *)malloc(strlen(base) * sizeof(char));
    char *backup = tmp;
    strcpy(tmp, base);
    tmp[strlen(delim)] = '\0';
    if (strcmp(tmp, delim) == 0)
    { 
        free(backup);
        return 1;
    }
    else
    {
        free(backup);
        return 0;
    }
}

int EndWith(char *base, char *delim)
{
    char *tmp = (char *)malloc(strlen(base) * sizeof(char));
    char *backup = tmp;
    strcpy(tmp, base);
    tmp += strlen(base) - strlen(delim);
    if (strcmp(tmp, delim) == 0)
    {
        free(backup);
        return 1;
    }
    else
    {
        free(backup);
        return 0;
    }
}

int Trim(char *base)
{
    while (isspace(base[0]))
        base[0] = '\0';
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}

int TrimStart(char *base)
{
    while (isspace(base[0]))
        base[0] = '\0';
    return strlen(base);
}

int main()
{
    char a[50];
    scanf("%s", a);
    char b[50];
    scanf("%s", b);
    printf("%d", EndWith(a, b));
}

void LoopOutInt(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
//冒泡排序，flag==0为升序，1为降序
void BubbleSort(int a[], int n, int flag)
{
    if (flag)
    {
        //降序，从大到小
        int i, j, temp;
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n - i; j++)
            {
                if (a[j] > a[j - 1])
                {
                    temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }
    }
    else
    {
        //升序，从小到大
        int i, j, temp;
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n - i; j++)
            {
                if (a[j] < a[j - 1])
                {
                    temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }
    }
}
//快速排序，flag==0为升序，1为降序
void QuickSort(int a[], int n, int flag)
{
    if (flag)
    {
        qsort(a, n, sizeof(a[0]), CompareFromHighToLow);
    }
    else
    {
        qsort(a, n, sizeof(a[0]), CompareFromLowToHigh);
    }
}
//快速排序的比较函数
int CompareFromLowToHigh(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); //升序
}
//快速排序的比较函数
int CompareFromHighToLow(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a); //降序
}
//组合数
int C(int n, int m)
{
    return getFactorial(n) / (getFactorial(m) * getFactorial(n - m));
}
//阶乘
int getFactorial(int n)
{
    if (n <= 1)
        return 1;
    return n * getFactorial(n - 1);
}
//设置某数的二进制位 ToSet仅为0/1
int SetBit(int Bit, int Number, int ToSet)
{
    int i = 1;
    i <<= Bit;
    if (ToSet == 1)
    {
        return (Number | i);
    }
    else
    {
        return (Number & (~i));
    }
}

int LoopBitLeft(int a, int n)
{
    return ((a >> (32 - n)) | (a << n)) % (1 << 32);
}