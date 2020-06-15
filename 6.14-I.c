#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);
char num[205];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    while (~scanf("%s%d", num, &n))
    {
        int spot;
        for (int i = 0; i < strlen(num); i++)
        {
            if (num[i] == '.')
            {
                spot = i;
                break;
            }
        }
        int last = spot + n;
        int carry = 0;
        if (num[last + 1] >= '5')
        {
            if (num[last] == '9')
            {
                carry = 1;
                num[last] = '0';
            }
            else
                num[last]++;
            while (carry)
            {
                
            }
        }
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}