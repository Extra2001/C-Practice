#include <stdio.h>

int main()
{
    freopen("./in2.txt", "w", stdout);
    printf("1000000 1000001\n");
    for (int i = 0; i < 1000000; i++)
    {
        printf("%d ", i);
    }
    fclose(stdout);
}