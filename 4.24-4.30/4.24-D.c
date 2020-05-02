#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dayTab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)));
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int year, month, day, cu_year, cu_month, cu_day;
    while (~scanf("%d%d%d", &year, &month, &day))
    {
        int count = 0;
        scanf("%d%d%d", &cu_year, &cu_month, &cu_day);
        int y = cu_year, m = cu_month, d = cu_day;
        for (;; y++)
        {
            int leap = isLeap(y);
            for (; m <= 12; m++)
            {
                for (; d <= dayTab[leap][m]; d++)
                {
                    if (m == month && d == day)
                    {
                        printf("%d\n", count);
                        goto loopend;
                    }
                    count++;
                }
                d = 1;
            }
            m = 1;
        }
    loopend:;
    }

    //fclose(stdin);
}