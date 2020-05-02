#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    char a[25], b[25];
    gets(a);
    gets(b);
    char *pa = a;
    int n = strlen(b);
    while ((pa = strstr(pa, b)) != NULL)
    {
        printf("%d-%d\n", pa - a, pa - a + n - 1);
        pa += n;
    }
    // fclose(stdin);
}