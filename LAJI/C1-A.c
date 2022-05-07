#include <stdio.h>

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &tmp);
        printf("%.2lf\n", tmp > 800 ? (800 + (tmp - 800) * 0.8) : (double)tmp);
    }
}