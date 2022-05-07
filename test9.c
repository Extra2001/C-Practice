#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hhh
{
    int score;
    int rank;
} contest;

typedef struct hh
{
    int id;
    char name[22];

    contest tests[50];
} stu;

typedef struct hhhh
{
    int id;
    char name[22];
    int score;
    int rank;
} contestinfo;

int number, k, op = 0, max, testcnt = 0;

stu stus[1005], *mystus[1005];

void readOpearation();

int main()
{
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    scanf("%d%d", &number, &k);
    max = number;
    for (int i = 0; i < number; i++)
    {
        scanf("%d%s", &stus[i].id, stus[i].name);
        mystus[i] = stus + i;
    }
    for (int i = 0; i < k; i++)
        readOpearation();
}

stu *find(int target)
{
    for (int i = 0; i < max; i++)
        if (stus[i].id == target)
            return stus + i;
    return NULL;
}

void addContest()
{
    int n, id, score, rank;
    char nametmp[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%d%d", &id, nametmp, &score, &rank);
        stu *p = find(id);
        if (p == NULL)
        {
            p = stus + max;
            max++;
            p->id = id;
            strcpy(p->name, nametmp);
        }
        p->tests[testcnt].rank = rank;
        p->tests[testcnt].score = score;
    }
    testcnt++;
}

void average()
{
    int n, cnt = 0;
    double sum = 0;
    scanf("%d", &n);
    if (n > testcnt)
    {
        printf("null\n\n");
        return;
    }
    for (int i = 0; i < number; i++)
        if (mystus[i]->tests[n - 1].rank != 0)
            sum += mystus[i]->tests[n - 1].score, cnt++;
    printf("%.2lf\n\n", sum / cnt);
}

void allAverage()
{
    int n, cnt = 0;
    double sum = 0;
    scanf("%d", &n);
    if (n > testcnt)
    {
        printf("null\n\n");
        return;
    }
    for (int i = 0; i < max; i++)
        if (stus[i].tests[n - 1].rank != 0)
            sum += stus[i].tests[n - 1].score, cnt++;
    printf("%.2lf\n\n", sum / cnt);
}

int cmp1(const void *_a, const void *_b)
{
    contestinfo *a = (contestinfo *)_a, *b = (contestinfo *)_b;
    return a->rank - b->rank;
}

void contestInfo()
{
    int n, cnt = 0;
    contestinfo a[1000];
    scanf("%d", &n);
    if (n > testcnt)
    {
        printf("null\n\n");
        return;
    }
    for (int i = 0; i < max; i++)
        if (stus[i].tests[n - 1].rank != 0)
        {
            a[cnt].id = stus[i].id;
            strcpy(a[cnt].name, stus[i].name);
            a[cnt].rank = stus[i].tests[n - 1].rank;
            a[cnt].score = stus[i].tests[n - 1].score;
            cnt++;
        }
    qsort(a, cnt, sizeof(a[0]), cmp1);
    for (int i = 0; i < cnt; i++)
        printf("%d\t%s\t%d\t%d\n", a[i].id, a[i].name, a[i].score, a[i].rank);
    printf("\n");
}

void allInfo()
{
    for (int i = 0; i < number; i++)
    {
        printf("%d\t%s", mystus[i]->id, mystus[i]->name);
        for (int j = 0; j < testcnt; j++)
        {
            if (mystus[i]->tests[j].rank != 0)
                printf("\t%d\t%d", mystus[i]->tests[j].score, mystus[i]->tests[j].rank);
            else
                printf("\tnan\tnan");
        }
        printf("\n");
    }
    printf("\n");
}

void studentInfo()
{
    int id;
    scanf("%d", &id);
    stu *p = find(id);
    if (p == NULL)
    {
        printf("null\n\n");
        return;
    }
    printf("%d\t%s", p->id, p->name);
    for (int i = 0; i < testcnt; i++)
    {
        if (p->tests[i].rank != 0)
            printf("\t%d\t%d", p->tests[i].score, p->tests[i].rank);
        else
            printf("\tnan\tnan");
    }
    printf("\n\n");
}

void readOpearation()
{
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        addContest();
        break;
    case 2:
        average();
        break;
    case 3:
        allAverage();
        break;
    case 4:
        contestInfo();
        break;
    case 5:
        allInfo();
        break;
    case 6:
        studentInfo();
        break;
    }
}