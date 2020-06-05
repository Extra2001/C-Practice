#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aa
{
    int value;
    int diff;
    int x;
    int y;
} obj;

obj a[100000];
int n;
int x = 1, y = 1;

int cmp(const void *a, const void *b)
{
    obj *e = (obj *)a;
    obj *f = (obj *)b;
    if (e->value == f->value)
    {
        if (e->diff == f->diff)
        {
            if (e->x == f->x)
                return e->y - f->y;
            else
                return e->x - f->x;
        }
        else
            return e->diff - f->diff;
    }
    else
        return f->value - e->value;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[cnt].value);
            a[cnt].x = i;
            a[cnt].y = j;
            cnt++;
        }
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[cnt].diff);
            cnt++;
        }
    }
    qsort(a, cnt, sizeof(a[0]), cmp);
    printf("%d %d", a[0].x, a[0].y);
    // fclose(stdin);
}