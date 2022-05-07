#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Untitled
{
    char name[505];
    double score;
} obj;

char laji[5];
obj a[10005];

int cmp(const void *_a, const void *_b)
{
    obj *a = (obj *)_a, *b = (obj *)_b;
    return a->score - b->score > 0 ? -1 : 1;
}

int main()
{
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\统计上机成绩\\in3.txt", "r", stdin);
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\统计上机成绩\\out13.txt", "w", stdout);
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int n, m, i;
    double tmp;
    scanf("%d%d", &n, &m);
    gets(laji);
    for (i = 0; i < n; i++)
    {
        gets(a[i].name);
        scanf("%lf", &tmp);
        a[i].score = tmp;
        gets(laji);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    for (i = 0; i < m; i++)
    {
        puts(a[i].name);
    }
}