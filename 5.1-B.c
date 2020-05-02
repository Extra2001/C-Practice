#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[12][12] = {0};

int main()
{
    memset(a, 48, sizeof(a));
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    for (int i = 1; i <= 10; i++)
    {
        gets(a[i] + 1);
        a[i][11] = '0';
    }
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
            if (a[i][j] == 'X')
                for (int k = -1; k <= 1; k++)
                    for (int m = -1; m <= 1; m++)
                        if (a[i + k][j + m] != 'X')
                            a[i + k][j + m]++;
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            if (a[i][j] == '0')
                putchar(' ');
            else
                putchar(a[i][j]);
        }
        putchar('\n');
    }
    // fclose(stdin);
}