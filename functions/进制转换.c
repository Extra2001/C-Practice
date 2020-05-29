#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OutInSys(int num, int sys)
{
    int m, i = 0;
    int b[1000];
    if (num == 0)
    {
        printf("0\n");
        return;
    }
    while (num)
    {
        b[i] = num % sys;
        i++;
        num = num / sys;
    }
    for (i = i - 1; i >= 0; i--)
    {
        if (abs(b[i]) == 10)
            printf("A");
        else if (abs(b[i]) == 11)
            printf("B");
        else if (abs(b[i]) == 12)
            printf("C");
        else if (abs(b[i]) == 13)
            printf("D");
        else if (abs(b[i]) == 14)
            printf("E");
        else if (abs(b[i]) == 15)
            printf("F");
        else
            printf("%d", abs(b[i]));
    }
    printf("\n");
}

int get10Sys(char *num, int sys)
{
    char *p = num;
    int len = strlen(p);
    int temp, sum = 0;
    while (len > 0)
    {
        char ss = toupper(*p);
        if (ss >= '0' && ss <= '9')
        {
            temp = (ss - '0') * pow(sys, len - 1);
            sum = sum + temp;
        }
        if (ss >= 'A' && ss <= 'F')
        {
            temp = (ss - 'A' + 10) * pow(sys, len - 1);
            sum = sum + temp;
        }
        p++;
        len--;
    }
    return sum;
}