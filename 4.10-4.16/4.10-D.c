#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[5000];

int main()
{
    //freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    gets(a);
    int n = strlen(a);
    int flag = 1;
    int i = 0;
    while (a[n - i - 1] == '0')
    {
        i++;
    }
    for (; i < n; i++)
    {
        printf("%c", a[n - i - 1]);
        flag = 0;
    }
    if (flag)
    {
        printf("0");
    }
    //fclose(stdin);
}