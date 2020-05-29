#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Four Pegs Hanoi
long long a[105];

void move4(int);

int main()
{
    int n;
    move4(100);
    while (~scanf("%d", &n)) {
        printf("%d\n", a[n]);
    }
}

void move4(int n)
{
    int i, j;
    a[1] = 1;
    a[2] = 3;
    for (i = 3; i <= n; i++)
    {
        a[i] = 100000000;
        for (j = 1; j < i; j++)
        {
            double temp = 2.0 * a[j] + pow(2, (double)i - (double)j) - 1;
            if (temp < a[i])
            {
                a[i] = temp;
            }
        }
    }
}