#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[100000];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    memset(a, 0, sizeof(a));
    int n;
    scanf("%d", &n);
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    if (n <= 3)
    {
        printf("%d", n);
        return 0;
    }
    for (int i = 4; i <= n; i++)
        a[i] = a[i - 1] + a[i - 3];
    printf("%d", a[n]);
}