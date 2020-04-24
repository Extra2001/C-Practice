#include <stdio.h>

int main()
{
    int a[3][4] = {1};
    int(*p)[4] = a;
    printf("地址：%d, 依次：%d %d %d %d %d %d\n", &a[1][0], p + 1, a + 1, p[1], (*p)[1], a[1], *(p[1]));
    char *weekday[] = {"Sun", "Mon", "Tus"};
    printf("%s %c %d %d", weekday[1], *weekday[1], &weekday[1]);
}