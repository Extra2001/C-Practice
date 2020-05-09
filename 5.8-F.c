#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ssss
{
    int a;
    char xy;
    char op;
    int b;
} zh;

zh a[200015];

int cmp(const void *aa, const void *bb)
{
    return ((zh *)aa)->a - ((zh *)bb)->a;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int N;
    int tmpa, tmpb;
    char tmpxy, tmpop;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %c%c%d", &tmpa, &tmpxy, &tmpop, &tmpb);
        a[i].a = tmpa;
        a[i].b = tmpb;
        a[i].op = tmpop;
        a[i].xy = tmpxy;
    }
    qsort(a, N, sizeof(a[0]), cmp);
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i].op == '+')
        {
            if (a[i].xy == 'X')
            {
                x += a[i].b;
            }
            else
            {
                y += a[i].b;
            }
        }
        else if (a[i].op == '-')
        {
            if (a[i].xy == 'X')
            {
                x -= a[i].b;
            }
            else
            {
                y -= a[i].b;
            }
        }
        else if (a[i].op == '*')
        {
            if (a[i].xy == 'X')
            {
                x *= a[i].b;
            }
            else
            {
                y *= a[i].b;
            }
        }
        else if (a[i].op == '/')
        {
            if (a[i].xy == 'X')
            {
                x /= a[i].b;
            }
            else
            {
                y /= a[i].b;
            }
        }
        else
        {
            if (a[i].xy == 'X')
            {
                x = a[i].b;
            }
            else
            {
                y = a[i].b;
            }
        }
    }
    printf("%d %d", x, y);
    // fclose(stdin);
}