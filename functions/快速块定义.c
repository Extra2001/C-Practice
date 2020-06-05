#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aa
{
    int value;
} obj;

int cmp(const void *a, const void *b)
{
    obj *e = (obj *)a, *f = (obj *)b;
    return e->value - f->value;
}

int cmp(const void *a, const void *b)
{
    int *e = (int *)a, *f = (int *)b;
    return *e - *f;
}