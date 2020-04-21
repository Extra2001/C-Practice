#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[200];

int main()
{
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    if(n==2){
        printf("2");
        return 0;
    }
    a[1] = 1;
    a[2] = 2;
    int sum = 0;
    for (int i = 3; i <= n; i++)
    {
        if (i & 1)
        {
            a[i] = a[i - 1];
        }
        else
        {
            a[i] = a[i - 2] + a[i / 2];
        }
    }
    printf("%d", a[n]);
    //fclose(stdin);
}