#include <stdio.h>

char *ans[10] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"};

int main()
{
    int n, x, y, k, days, week;
    while (scanf("%d %d %d %d", &n, &x, &y, &k) > 0)
    {
        days = n + k - x + y;

        week = days % 7;

        printf("%s\n", ans[week]);
        
    }
}