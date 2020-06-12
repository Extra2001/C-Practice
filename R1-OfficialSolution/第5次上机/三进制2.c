#include <stdio.h>
#include <string.h>

#define N 10005

char x[10005] = {0}, y[10005] = {0}, tmp[N];
int m[10005] = {0}, n[10005] = {0}, ans[10005] = {0};

void input()
{
    int lenX = strlen(x), lenY = strlen(y);
    int top, i;
    for (i = lenX - 1, top = 0; i >= 1; --i)
    {
        // if (x[i] < '0')
        // {
        //     continue;
        // }
        m[top] = x[i] - '0';
        top++;
    }
    if (x[0] != '-')
    {
        m[top] = x[0] - '0';
    }

    for (i = lenY - 1, top = 0; i >= 1; --i)
    {
        // if (y[i] < '0')
        // {
        //     continue;
        // }
        n[top] = y[i] - '0';
        top++;
    }
    if (y[0] != '-')
    {
        n[top] = y[0] - '0';
    }
}

void init()
{
    int i;
    for (i = 0; i < 10005; ++i)
    {
        m[i] = 0;
        n[i] = 0;
        ans[i] = 0;
    }
}

void print(int *cc, int sig)
{
    int i;
    int begin = 0, top = 0;
    for (i = 10004; i >= 0; --i)
    {
        if (cc[i]>0)
        {
            begin = 1;
        }
        if (begin)
        {
            tmp[top] = cc[i] + '0';
            top++;
        }
    }
    if (begin == 0)
    {
        printf("0\n");
        return;
    }
    tmp[top] = 0;
    if (sig < 0)
    {
        putchar('-');
    }
    printf("%s\n", tmp);
}

int cmp(int *mm, int *nn)
{
    int i;
    for (i = N - 1; i >= 0; --i)
    {
        if (mm[i] > nn[i])
        {
            return 1;
        }
        else if (nn[i] > mm[i])
        {
            return -1;
        }
    }

    return 0;
}

void add()
{
    int i, plus;
    for (i = 0, plus = 0; i < N; ++i)
    {
        ans[i] = m[i] + n[i] + plus;
        plus = ans[i] / 3;
        ans[i] = ans[i] % 3;
    }
}

void mul(int *mm, int *nn)
{
    int i, top;
    for (i = 0; i <N; ++i)
    {
        ans[i] += (mm[i] - nn[i]);
        while (ans[i] < 0)
        {
            ans[i] += 3;
            ans[i + 1] -= 1;
        }
    }
}

int main()
{
    int cm;
    while (gets(x) != NULL)
    {
        init();
        gets(y);
        input();
        // print(cmp(m,n));
        // printf("%d", cmp(m, n));

        if (x[0] == '-' && y[0] == '-')
        { // 都负,加起来
            add();
            print(ans, -1);
        }
        else if (x[0] == '-' && y[0] != '-') // n减m
        {
            cm = cmp(m, n);
            if (cm > 0)
            {
                mul(m, n);
                print(ans, -1);
            }
            else if (cm < 0)
            {
                mul(n, m);
                print(ans, 1);
            }
            else
            {
                printf("0\n");
            }
        }
        else if (x[0] != '-' && y[0] == '-') // m减n
        {
            cm = cmp(m, n);
            if (cm > 0)
            {
                mul(m, n);
                print(ans, 1);
            }
            else if (cm < 0)
            {
                mul(n, m);
                print(ans, -1);
            }
            else
            {
                printf("0\n");
            }
        }
        else // 两正数加起来
        {
            add();
            print(ans, 1);
        }
    }
}