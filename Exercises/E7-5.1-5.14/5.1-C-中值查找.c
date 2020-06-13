#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int school[1000015];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n;
    scanf("%d%d", &m, &n);
    int sum = 0, tmp;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        school[tmp] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        int buffer1 = tmp, buffer2 = tmp;
        if (school[tmp] == 0)
        {
            int flag1 = 0, flag2 = 0;
            while ((!flag1) && (!flag2))
            {
                buffer1++;
                buffer2--;
                flag1 = school[buffer1];
                flag2 = school[buffer2];
            }
            if(flag1)
                sum += abs(buffer1 - tmp);
            else
                sum += abs(buffer2 - tmp);
        }
    }
    printf("%d", sum);
    // fclose(stdin);
}