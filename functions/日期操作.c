#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char months[13][8] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};

char weeks[8][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int dayTab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)));
}

int verify(int year, int month, int day)
{
    if (month <= 0 || day <= 0)
        return 0;
    if (month > 12)
        return 0;
    if (day > dayTab[isLeap(year)][month])
        return 0;
    return 1;
}

//格式为yyyymmdd
void strToInt(char *str, int *year, int *month, int *day)
{
    *year = 0, *day = 0, *month = 0;
    int b = 1;
    int i;
    for (i = 0; i < 4; i++)
    {
        *year += b * (str[3 - i] - '0');
        b *= 10;
    }
    *month += (str[4] - '0') * 10;
    *month += str[5] - '0';
    *day += (str[6] - '0') * 10;
    *day += str[7] - '0';
}

//格式为yyyymmdd
int verifyByStr(char *str)
{
    int year = 0, day = 0, month = 0;
    strToInt(str, &year, &month, &day);
    return verify(year, month, day);
}

int countDay(char *start)
{
    int year = 0, day = 0, month = 0;
    strToInt(start, &year, &month, &day);
    int cnt = 0;
    for (;; year++)
    {
        for (; month < 13; month++)
        {
            for (; day <= dayTab[isLeap(year)][month]; day++)
            {
                //终止条件在这
                if (year == 2019 && month == 4 && day == 2)
                    return cnt;
                cnt++;
            }
            day = 1;
        }
        month = 1;
    }
}