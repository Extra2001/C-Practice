#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumd[1000015] = {1, 2};

void getFactorial(int n)
{
    long long res = 1;
    int i;
    for (i = 2; i <= n; i++)
    {
        res = (i * res % 1000003);
        sumd[i] = (sumd[i - 1] + res) % 1000003;
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    getFactorial(1000001);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", sumd[a]);
    }
    // fclose(stdin);
}