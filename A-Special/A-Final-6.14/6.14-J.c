#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);
typedef struct ti
{
    int Ques;
    int status;
    int time;
    int savedtime;
} que;

typedef struct st
{
    int ID;
    int AC;
    int time;
    int lasttime;
    int cnt;
    que ques[105];
} stu;

stu stus[5005];
int cnt;

int read()
{
    int time, ID, res;
    char timu;
    int flag = scanf("%d%d %c %d", &time, &ID, &timu, &res);
    if (flag == EOF)
        return EOF;
    int nowID = -1;
    for (int i = 0; i < cnt; i++)
    {
        if (stus[i].ID == ID)
            nowID = i;
    }
    if (nowID == -1)
        nowID = cnt++;
    int nowQues = -1;
    for (int i = 0; i < stus[nowID].cnt; i++)
    {
        if (stus[nowID].ques[i].Ques == timu)
            nowQues = i;
    }
    if (nowQues == -1)
        nowQues = stus[nowID].cnt++;
    stus[nowID].ques[nowQues].Ques = timu;
    stus[nowID].ID = ID;
    stus[nowID].ques[nowQues].time = time;
    if (stus[nowID].ques[nowQues].status == 0)
    {
        stus[nowID].ques[nowQues].status = res;
        if (res == 0)
            stus[nowID].ques[nowQues].savedtime += 20 * 60;
        else
        {
            stus[nowID].time += time + stus[nowID].ques[nowQues].savedtime;
            stus[nowID].AC++;
            stus[nowID].lasttime = time;
            stus[nowID].ques[nowQues].savedtime = 0;
        }
    }
    return 1;
}

int cmp(const void *a, const void *b)
{
    stu *e = (stu *)a, *f = (stu *)b;
    if (e->AC == f->AC)
    {
        if (e->time == f->time)
        {
            return e->lasttime - f->lasttime;
        }
        return e->time - f->time;
    }
    return f->AC - e->AC;
}

int count = 1;

void print(int i)
{
    if (stus[i].AC == 0)
    {
        return;
    }
    stu *u = &stus[i];
    int h = u->time / 3600, m = (u->time / 60) % 60, s = u->time % 60;
    printf("%d %d %d %d:%02d:%02d\n", count, u->ID, u->AC, h, m, s);
    count++;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m;
    IN2(n, m);
    while (read() != EOF)
        ;
    qsort(stus, n, sizeof(stus[0]), cmp);
    for (int i = 0; i < n; i++)
    {
        print(i);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}