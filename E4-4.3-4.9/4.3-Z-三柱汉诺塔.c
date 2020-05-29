#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(int n, char from, char to)
{
    printf("move %d from %c to %c\n", n, from, to);
}

void hanoi(int n, char from, char via, char to)
{
    if (n == 1)
    {
        move(n, from, to);
        return;
    }
    hanoi(n - 1, from, to, via); // 把n-1个盘子从from通过
    move(n, from, to);
    hanoi(n - 1, via, from, to);
}

//次数
double move3(int n)
{
    return pow(2, n) - 1;
}