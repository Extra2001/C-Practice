#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int TrimEndR(char *base);

int weight[20] = {
    7,
    9,
    10,
    5,
    8,
    4,
    2,
    1,
    6,
    3,
    7,
    9,
    10,
    5,
    8,
    4,
    2,
};
int verifyArr[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

char s[20];

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

int verifyID(char *str)
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
    {
        if (isdigit(str[i]))
            sum += (str[i] - '0') * weight[i];
        else
            return 0;
    }
    sum %= 11;
    if (toupper(str[17]) == verifyArr[sum])
        return 1;
    else
        return 0;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    gets(s);
    if (TrimEndR(s) != 18)
    {
        printf("Chawuciren");
        return 0;
    }
    if (verifyByStr(s + 6) == 0)
    {
        printf("Chawuciren");
        return 0;
    }
    if (verifyID(s) == 0)
    {
        printf("Chawuciren");
        return 0;
    }
    int year = 0, day = 0, month = 0;
    strToInt(s + 6, &year, &month, &day);
    int cnt = 0;
    for (; year <= 2019; year++)
    {
        for (; month < 13; month++)
        {
            for (; day <= dayTab[isLeap(year)][month]; day++)
            {
                if (year == 2019 && month == 4 && day == 2)
                {
                    printf("%d", cnt);
                    goto end;
                }
                cnt++;
            }
            day = 1;
        }
        month = 1;
    }
end:;
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}