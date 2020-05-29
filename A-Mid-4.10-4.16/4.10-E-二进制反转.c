#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int SetBit(int Bit, unsigned int Number, int ToSet)
{
    int i = 1;
    i <<= Bit;
    if (ToSet == 1)
    {
        return (Number | i);
    }
    else
    {
        return (Number & (~i));
    }
}
int main()
{
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    unsigned int a;
    scanf("%u", &a);
    unsigned int b = 0;
    for (int i = 0; i < 8; i++)
    {
        int wei = (a >> 24 + i) & 1;
        b = SetBit(i, b, wei);
    }
    for (int i = 0; i < 8; i++)
    {
        int wei = (a >> 16 + i) & 1;
        b = SetBit(i + 8, b, wei);
    }
    for (int i = 0; i < 8; i++)
    {
        int wei = (a >> 8 + i) & 1;
        b = SetBit(i + 16, b, wei);
    }
    for (int i = 0; i < 8; i++)
    {
        int wei = (a >> i) & 1;
        b = SetBit(i + 24, b, wei);
    }
    printf("%u", b);
    //fclose(stdin);
}