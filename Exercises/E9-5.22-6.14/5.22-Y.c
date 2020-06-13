#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aa
{
    int value;
    int sort;
} obj;

int cmp(const void *a, const void *b)
{
    obj *e = (obj *)a, *f = (obj *)b;
    return e->value - f->value;
}

obj a[10000];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);

    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        a[i].value = tmp;
        a[i].sort = i+1;
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i].sort);
    }
}