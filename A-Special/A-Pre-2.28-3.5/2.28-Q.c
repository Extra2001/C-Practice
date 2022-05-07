#include <math.h>
#include <stdio.h>

int main()
{
    char str[110];
    gets(str);
    printf("%s", str + 3);
    return 0;
}