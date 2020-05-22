#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

typedef struct aa
{
    char me[60];
    int day;
    int month;
} peo;

peo peos[50005];

int dayTab[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int cmp(const void *a, const void *b)
{
    peo *e = (peo *)a, *f = (peo *)b;
    if (e->month == f->month)
    {
        if (e->day == f->day)
        {
            return strcmp(e->me, f->me);
        }
        else
        {
            return e->day - f->day;
        }
    }
    else
    {
        return e->month - f->month;
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %*d:%d:%d", peos[i].me, &peos[i].month, &peos[i].day);
    }
    qsort(peos, n, sizeof(peos[0]), cmp);
    int cum = peos[0].month, cud = peos[0].day;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("%d:%d %s", peos[i].month, peos[i].day, peos[i].me);
        }
        else
        {
            if (peos[i].month == cum && peos[i].day == cud)
            {
                printf(" %s", peos[i].me);
            }
            else
            {
                printf("\n%d:%d %s", peos[i].month, peos[i].day, peos[i].me);
                cum = peos[i].month;
                cud = peos[i].day;
            }
        }
    }
    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}