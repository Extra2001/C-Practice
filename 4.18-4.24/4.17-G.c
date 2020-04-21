#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[105][105];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    char laji[2];
    gets(laji);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            scanf("%c", &a[i][j]);
        gets(laji);
    }
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
            if (islower(a[i][j]))
                printf("%c", a[i][j]);
        for (int j = i; j < n - i - 1; j++)
            if (islower(a[j][n - i - 1]))
                printf("%c", a[j][n - i - 1]);
        for (int j = n - i - 1; j > i; j--)
            if (islower(a[n - i - 1][j]))
                printf("%c", a[n - i - 1][j]);
        for (int j = n - i - 1; j > i; j--)
            if (islower(a[j][i]))
                printf("%c", a[j][i]);
    }
    if (n % 2 == 1)
    {
        if (islower(a[n / 2][n / 2]))
            printf("%c", a[n / 2][n / 2]);
    }
    printf("\n");
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
            if (isupper(a[j][i]))
                printf("%c", a[j][i]);
        for (int j = i; j < n - i - 1; j++)
            if (isupper(a[n - i - 1][j]))
                printf("%c", a[n - i - 1][j]);
        for (int j = n - i - 1; j > i; j--)
            if (isupper(a[j][n - i - 1]))
                printf("%c", a[j][n - i - 1]);
        for (int j = n - i - 1; j > i; j--)
            if (isupper(a[i][j]))
                printf("%c", a[i][j]);
    }
    if (n % 2 == 1)
    {
        if (isupper(a[n / 2][n / 2]))
            printf("%c", a[n / 2][n / 2]);
    }

    // fclose(stdin);
}