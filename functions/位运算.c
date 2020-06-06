#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//设置某数的二进制位 ToSet仅为0/1
int setBit(int Bit, int ToSet, int *Number)
{
    int i = 1;
    i <<= Bit;
    if (ToSet == 1)
        *Number = (*Number | i);
    else
        *Number = ((*Number) & (~i));
    return *Number;
}

int getBit(int Bit, int Number)
{
    return (Number >> Bit) & 1;
}

//n为左移的位数
int loopBitLeft(int Number, int n)
{
    return ((Number >> (32 - n)) | (Number << n)) % (1 << 32);
}

//n为左移的位数
int loopBitRight(int Number, int n)
{
    return ((Number << (32 - n)) | (Number >> n)) % (1 << 32);
}