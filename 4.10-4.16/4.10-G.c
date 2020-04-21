#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sec[1005];
int loop[1005];
int main()
{
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n = 0;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &sec[i]);
        }
        int max = 0, flag = 1;
        for (int i = 1; i < n; i++)
        {
            int count = 0, curr = sec[i];
            memset(loop, 0, sizeof(loop));
            loop[i] = 1;
            while (1)
            {
                if (curr == n)
                {
                    count++;
                    break;
                }
                if (loop[curr])
                {
                    flag = 0;
                    break;
                }
                loop[curr] = 1;
                count++;
                curr = sec[curr];
            }
            if (flag == 0)
            {
                break;
            }
            if (max < count)
            {
                max = count;
            }
            
        }
        if (flag)
        {
            printf("%d\n", max);
        }
        else
        {
            printf("No solution!\n");
        }
    }
    //fclose(stdin);
}