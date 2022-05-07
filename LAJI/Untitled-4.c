#include <stdio.h>

int dOfM[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dOfMR[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int getDiff(int py, int pm, int pd, int ty, int tm, int td)
{
    int diff = 0, i;
    if (py < ty && isLeapYear(py) && pm <= 2)
        diff += 366;
    else if (py < ty)
        diff += 365;
    for (i = 1; i < ty - py - 1; i++)
        diff += isLeapYear(py + i) ? 366 : 365;
    if (i < ty - py)
    {
        if (isLeapYear(py + i) && pm <= 2)
            diff += 366;
        else if (isLeapYear(ty) && tm > 2)
            diff += 366;
        else
            diff += 365;
    }
    for (i = 0; i < tm - pm; i++)
        diff += isLeapYear(ty) ? dOfMR[pm + i] : dOfM[pm + i];
    for (i = 0; i < pm - tm; i++)
        diff -= isLeapYear(ty) ? dOfMR[pm - i - 1] : dOfM[pm - i - 1];
    diff += td - pd;
    return diff;
}

int main()
{

    int py, pm, pd, ty, tm, td;
    int n, diff;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d-%d-%d %d-%d-%d", &py, &pm, &pd, &ty, &tm, &td);
        diff = getDiff(py, pm, pd, ty, tm, td);
        if (diff == 0)
            printf("Today\n");
        else if (diff == 1)
            printf("Yesterday\n");
        else if (ty == py && tm == py)
            printf("%d days ago\n", diff);
        else if (ty == py)
            printf("%02d-%02d %d days ago\n", pm, pd, diff);
        else
            printf("%04d-%02d-%02d %d days ago\n", py, pm, pd, diff);
    }
    return 0;
}