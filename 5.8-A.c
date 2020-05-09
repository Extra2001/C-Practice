#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[25][100];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, i, j;
    scanf("%d%d%d", &m, &i, &j);
    gets(a[0]);
    for (int k = 0; k < m; k++)
        gets(a[k]);
    putchar(a[i - 1][j - 1]);
    putchar('\n');
    char *p = &a[i - 1][j - 1];
    puts(p);
    // fclose(stdin);
}