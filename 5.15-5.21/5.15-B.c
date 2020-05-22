#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

typedef struct aa
{
    long long x;
    long long y;
} po;

typedef struct bb
{
    po zx;
    po ys;
    long long chang;
    long long kuan;
} rec;

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    po r1, r2, l1, l2;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &r1.x, &r1.y, &r2.x, &r2.y, &l1.x, &l1.y, &l2.x, &l2.y);
    rec rec1 = {r1, r2, r2.x - r1.x, r2.y - r1.y};
    rec rec2 = {l1, l2, l2.x - l1.x, l2.y - l1.y};
    rec *a = &rec1;
    rec *b = &rec2;
    if (rec1.zx.x > rec2.zx.x)
    {
        rec *tmp = a;
        a = b;
        b = tmp;
    }
    if (a->zx.x + a->chang >= b->zx.x)
    {
        long long x = a->chang - (b->zx.x - a->zx.x);
        if (a->ys.x > b->ys.x)
        {
            x -= a->ys.x - b->ys.x;
        }
        if (a->zx.y > b->zx.y)
        {
            rec *tmp = a;
            a = b;
            b = tmp;
        }
        if (a->zx.y + a->kuan >= b->zx.y)
        {
            long long y = a->kuan - (b->zx.y - a->zx.y);
            if (a->ys.y > b->ys.y)
            {
                y -= a->ys.y - b->ys.y;
            }
            printf("%lld", x * y);
            return 0;
        }
    }
    printf("0");
    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}