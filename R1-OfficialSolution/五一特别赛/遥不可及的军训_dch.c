#include <stdio.h>

int a[1005], b[1005], c[1005] = {0};
int n[1005];
int N, ans = 0;

void f(int i)
{
    if (c[i] == 0)
    {
        if(i!=b[i]){
            ans++;
        }
        c[i] = 1;
        f(b[i]);
    }
}

int main()
{
    int i, j, t;
scanf("%d",&N);
    for (i = 0; i < N; ++i)
    {
        scanf("%d", a + i);
        b[i] = i;
    }

    for (i = 0; i < N; ++i)
    {
        for (j = i; j < N; ++j)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
    }

    for (i = 0; i < N; ++i)
    {
        f(i);
    }

    printf("%d", ans);
}