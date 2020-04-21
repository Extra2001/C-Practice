#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[100005];
int b[100005];
int stu[10005];
int CompareFromLowToHigh(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); //升序
}

int main()
{
    freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m, c, d;
    while (~scanf("%d%d", &n, &m))
    {
        memset(&a, 0, sizeof(a));
        memset(&b, 0, sizeof(b));
        memset(&stu, 0, sizeof(stu));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &c);
            a[c] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &d);
            b[d] = 1;
        }
        int count = 0;
        for (int i = 0; i < 100005; i++)
        {
            if (a[i])
            {
                if (b[i] == 0)
                {
                    stu[count] = i;
                    count++;
                }
            }
            else
            {
                if (b[i])
                {
                    stu[count] = i;
                    count++;
                }
            }
        }
        qsort(stu, count, sizeof(stu[0]), CompareFromLowToHigh);
        for (int i = 0; i < count; i++)
        {
            printf("%d ", stu[i]);
        }
        printf("\n");
    }
    fclose(stdin);
}