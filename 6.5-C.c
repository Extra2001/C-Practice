#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);
typedef struct aa
{
    int sort;
    int value[15];
} obj;
int n, k;
obj a[1000];

int cmp(const void *a, const void *b)
{
    obj *e = (obj *)a, *f = (obj *)b;
    for (int i = 0; i < k; i++)
    {
        if (e->value[i] != f->value[i])
            return e->value[i] - f->value[i];
    }
    return e->sort - f->sort;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    IN2(n, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            IN1(a[i].value[j]);
            a[i].sort = i + 1;
        }
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i].sort);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}