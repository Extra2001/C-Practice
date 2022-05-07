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
    int p, q;
} obj;

int cmp(const void *a, const void *b)
{
    obj *e = (obj *)a, *f = (obj *)b;
    return e->p - f->p;
}

obj a[6000];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n;
    IN2(n, m);
    long long cnt = 0;
    for (int i = 0; i < m; i++)
    {
        IN2(a[i].p, a[i].q);
    }
    qsort(a, m, sizeof(a[0]), cmp);
    obj *po = a;
    while (n)
    {
        if (po->q <= 0)
            po++;
        po->q--;
        cnt += po->p;
        n--;
    }
    printf("%d", cnt);
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}