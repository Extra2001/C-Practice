#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int a[1000055] = {0};

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, k, tmp;
    IN1(n);
    for (int i = 0; i < n; i++)
    {
        IN1(tmp);
        a[tmp]++;
    }
    IN1(k);
    for (int i = n - 1, j = 0; i >= 0; i--)
    {
        if (a[i])
        {
            j++;
        }
        if (j == k)
        {
            printf("%d %d", i, a[i]);
            return 0;
        }
    }
    // fclose(stdin);
}