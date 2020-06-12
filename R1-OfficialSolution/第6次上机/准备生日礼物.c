#include <stdio.h>

int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeap(int y)
{
    if (y % 400 == 0)
    {
        return 1;
    }
    else if (y % 100 == 0)
    {
        return 0;
    }
    else if (y % 4 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 以1999年1月1日为起点的天数
int getDay(int yy, int mm, int dd, int y1, int m1, int d1)
{
    int y = y1, m = m1, d = d1, ans = 0, thisM;
    while (y < yy || m < mm || d < dd)
    {
        d++;
        ans++;
        thisM = day[m];
        if(m==2){
            thisM+=isLeap(y);
        }
        if (d > thisM)
        {
            d = 1;
            m++;
        }

        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
    return ans;
}

int main()
{
    int hd, hy, hm, ty, tm, td, day1, day2;

    while (scanf("%d %d %d", &hy, &hm, &hd) > 0)
    {
        scanf("%d %d %d", &ty, &tm, &td);
        if (hm * 100 + hd < tm * 100 + td)
        {
            hy = ty + 1;
        }
        else
        {
            hy = ty;
        }

        if (hm == 2 && hd == 29)
        {
            for (; hy <= 2999; hy++)
            {
                if (isLeap(hy))
                {
                    break;
                }
            }
        }
        day1 = getDay(hy, hm, hd, ty, tm, td);
        printf("%d\n", day1);
    }
}