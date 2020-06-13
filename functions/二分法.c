#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//递减的查找
int *fuzzyBSearch(int *key, int *base, int count)
{
    int left = 0, right = count - 1, mid;
    while (1)
    {
        mid = (left + right) / 2;
        if (base[mid] == *key)
        {
            while (base[mid] == *key)
                mid++;
            return base + mid - 1;
        }
        else if (right - left >= 4)
        {
            if (base[mid] > *key)
                left = mid;
            else
                right = mid;
        }
        else
        {
            while (base[mid] > *key && mid < count)
                mid++;
            while (base[mid] < *key && mid >= 0)
                mid--;
            if (mid < 0 || mid >= count)
                return NULL;
            return base + mid;
        }
    }
}

//递增的查找
int *fuzzyBSearch(int *key, int *base, int count)
{
    int left = 0, right = count - 1, mid;
    while (1)
    {
        mid = (left + right) / 2;
        if (base[mid] == *key)
        {
            while (base[mid] == *key)
                mid--;
            return base + mid + 1;
        }
        else if (right - left >= 4)
        {
            if (base[mid] > *key)
                right = mid;
            else
                left = mid;
        }
        else
        {
            while (base[mid] > *key && mid < count)
                mid--;
            while (base[mid] < *key && mid >= 0)
                mid++;
            if (mid < 0 || mid >= count)
                return NULL;
            return base + mid;
        }
    }
}

#define EPSILON 1e-8

//单调递增时最后一个参数为1，递减时为-1
double solve(double (*func)(double), double left, double right, int asc)
{
    double mid, tmp;
    while (right - left >= EPSILON)
    {
        mid = (right + left) / 2;
        tmp = func(mid);
        if (fabs(tmp) < EPSILON)
            return mid;
        else if (asc * tmp > 0)
            right = mid;
        else
            left = mid;
    }
    return mid;
}