#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    int i, sum = 0;
    for (i = 1; sum < t; i++)
        sum += i;
    int n = sum - t + 1;
    if (i & 1)
        printf("%d/%d", i - n, n);
    else
        printf("%d/%d", n, i - n);
    // fclose(stdin);
}