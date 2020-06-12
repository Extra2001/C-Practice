#include <stdio.h>
int n;
char ch[60][60];
int main()
{
    int n, i, x, y;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        x = i, y = i;
        do
        {
            ch[x][y] = 'A' + i;
            if (y == i && x < (n<<1) - 2 - i)x++;
            else if (x == (n<<1) - 2 - i && y < (n<<1) - 2 - i)y++;
            else if (y == (n<<1) - 2 - i && x > i)x--;
            else if (x == i && y > i)y--;
        }while (x != i || y != i);
    }
    for (i = 0; i < (n<<1) - 1; i++)
        printf("%s\n", ch[i]);
    return 0;
}