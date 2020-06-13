#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[1000] = {0};

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    while (gets(a + strlen(a)) != NULL)
        ;
    for (int i = strlen(a) - 1; i >= 0; i--)
    {
        if (isalpha(a[i]))
            putchar(a[i]);
    }
    // fclose(stdin);
}