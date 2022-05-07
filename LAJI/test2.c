#include <stdio.h>

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int a, n;
    while ((scanf("%d", &a)) != EOF)
    {
        n = 0;
        while ((a / 5) > 0)
        {
            n += (a / 5);
            a /= 5;
        }
        printf("%d\n", n);
    }
    return 0;
}
