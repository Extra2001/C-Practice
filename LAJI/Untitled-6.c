#include <stdio.h>

int dOfM[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dOfMR[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int getDiff(int py, int pm, int pd, int ty, int tm, int td)
{
    int diff = 0;
    int y = py, m = pm, d = pd;
    while (!(y == ty && m == tm && d == td))
    {
        diff++;
        if (++d > (isLeapYear(y) ? dOfMR[m] : dOfM[m]))
            d = 1, m++;
        if (m > 12)
            m = 1, y++;
    }
    return diff;
}

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\日期指示器\\in0.txt", "r", stdin);
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\日期指示器\\out20.txt", "w", stdout);
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
        else if (ty == py && tm == pm)
            printf("%d days ago\n", diff);
        else if (ty == py)
            printf("%02d-%02d %d days ago\n", pm, pd, diff);
        else
            printf("%04d-%02d-%02d %d days ago\n", py, pm, pd, diff);
    }
    return 0;
}