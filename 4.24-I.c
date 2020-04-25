#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nums[100015];

int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, target;
    while (~scanf("%d%d", &n, &target))
    {
        memset(nums, 0, sizeof(nums));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &nums[i]);
        }
        qsort(nums, n, sizeof(int), comp);
        int l = 0, r = n - 1;
        int sum = nums[l] + nums[r];
        while (sum != target)
        {
            sum = nums[l] + nums[r];
            if (sum < target)
            {
                l++;
            }
            else if (sum > target)
            {
                r--;
            }
        }
        printf("%d %d\n", nums[l], nums[r]);
    }
    //fclose(stdin);
}