#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aa
{
    char name[30];
    int value;
    int order;
} peo;

peo pe[10020];
int find(int l, int r, int key);

int comp(const void *a, const void *b)
{
    peo *e = (peo *)a, *f = (peo *)b;
    if (e->value == f->value)
        return e->order - f->order;
    return e->value - f->value;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%s %d", pe[i].name, &pe[i].value);
        pe[i].order = i;
    }
    qsort(pe, m, sizeof(pe[0]), comp);
    long long tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        int index = find(0, m - 1, tmp);
        peo *p = &pe[index];
        if (index >= m || abs(p->value - tmp) > 5)
            printf("POSITION ZERO\n");
        else
            for (; p->value <= tmp + 5LL && p - pe < m; p++)
                printf("%s %d\n", p->name, p->value);
        putchar('\n');
    }
    // fclose(stdin);
}

int find(int l, int r, int key)
{
    int mid;
    while (r - l > 4)
    {
        mid = (l + r) / 2;
        if (pe[mid].value > key - 5)
            r = mid;
        else if (pe[mid].value < key - 5)
            l = mid;
        else
        {
            r = mid;
            break;
        }
    }
    while (r >= 0 && pe[r].value >= key - 5)
        r--;
    return r + 1;
}