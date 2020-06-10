#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SetBit(int Bit, int Number, int ToSet);
int TrimEnd(char *base);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    unsigned int n, res;
    scanf("%u", &n);
    res = 0;
    for (int i = 0; i < 16; i++)
        res = SetBit(16 + i, res, (n >> i) & 1);
    for (int i = 0; i < 16; i++)
        res = SetBit(i, res, (n >> 16 + i) & 1);
    printf("%u", res);
    // fclose(stdin);
}

int SetBit(int Bit, int Number, int ToSet)
{
    int i = 1;
    i <<= Bit;
    if (ToSet == 1)
        return (Number | i);
    else
        return (Number & (~i));
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}