#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char week[13][8] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
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
    int count1 = 0, count2 = 0, y, m, d;
    char year[20];
    scanf("%s%d%d", &year, &d, &y);
    for (int i = 0; i < 13; i++)
    {
        if (strcmp(week[i], year) == 0)
        {
            m = i;
            break;
        }
    }
    for (; m < 13; m++)
    {
        for (; d <= dayTab[isLeap(y)][m]; d++)
        {
            if (d == 13)
            {
                count2++;
            }
            count1++;
            if (m == 12 && d == 31)
            {
                goto out;
            }
        }
        d = 1;
    }
out:;
    printf("%d %d", count1 - 1, count2);
    // fclose(stdin);
}