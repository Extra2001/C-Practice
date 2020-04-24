#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nums[10015];

int asc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); //升序
}

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, target;
    while (~scanf("%d%d", &n, &target))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &nums[i]);
        }
        qsort(nums, n, sizeof(int), asc);
        int *curr = nums;
        // int nn = target / 2;
        int cur = 0;
        int l = 0, r = 0;
        while (*curr < target)
        {
            int to = target - *curr;
            int *b = (int *)bsearch(&to, curr + 1, n - cur, sizeof(int), comp);
            if (b != NULL)
            {
                if (abs(l - r) < abs(to - *curr))
                {
                    l = to;
                    r = *curr;
                }
            }
            cur++;
            curr++;
        }
        if (l > r)
        {
            int temp = l;
            l = r;
            r = temp;
        }
        printf("%d %d\n", l, r);
    }

    //fclose(stdin);
}