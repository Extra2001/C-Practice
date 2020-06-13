#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p
{
    int x;
    int y;
} point;

point a[500015];

int asc(const void *a, const void *b)
{
    int ret = ((point *)a)->y - ((point *)b)->y;
    if (ret == 0)
    {
        return ((point *)a)->x - ((point *)b)->x;
    }
    else
    {
        return ret;
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in2.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    qsort(a, n, sizeof(&a[0]), asc);
    double zhou, zhou1;
    int flag = 1;
    int flag1 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i].y != a[j].y)
            {
                for (int l = i, r = j - 1; l <= r; l++, r--)
                {
                    if (flag1)
                    {
                        zhou1 = (a[l].x + a[r].x) / 2.0;
                        flag1 = 0;
                        zhou = zhou1;
                    }
                    else
                    {
                        zhou = (a[l].x + a[r].x) / 2.0;
                        if (zhou != zhou1)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                i = j;
            }
        }
    }
    if (flag)
    {
        printf("x = %.1f\n", zhou1);
    }
    else
    {
        printf("Not a symmetric figure.\n");
    }
    // fclose(stdin);
}