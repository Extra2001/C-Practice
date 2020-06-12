#include <stdio.h>

int main()
{
    unsigned int a, b;
    scanf("%u", &a);
    b = ((a & 0XFF000000U) >> 24) +
        ((a & 0X00FF0000U) >> 8) +
        ((a & 0X0000FF00U) << 8) +
        ((a & 0X000000FFU) << 24);
    printf("%u", b);
}