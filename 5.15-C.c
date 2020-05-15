#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

typedef struct aa
{
    char mess[150];
    int uid;
    int rate;
} peo;

peo pros[100005];

int cmp(const void *a, const void *b)
{
    peo *e = (peo *)a, *f = (peo *)b;
    if (e->rate == f->rate)
    {
        return e->uid - f->uid;
    }
    return f->rate - e->rate;
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    char rub[20];
    gets(rub);
    for (int i = 0; i < n; i++)
    {
        gets(pros[i].mess);
        sscanf(pros[i].mess, "%*s %d%d", &pros[i].uid, &pros[i].rate);
    }
    qsort(pros, n, sizeof(pros[0]), cmp);
    puts(pros[0].mess);
    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}