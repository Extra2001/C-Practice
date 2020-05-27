#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[50], flags[50] = {0};
int cnt;
void A(int n, int cur);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    while (~scanf("%d", &cnt))
        A(0, 0);
    // fclose(stdin);
}

void Out()
{
    for (int i = 1; i <= cnt; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void A(int n, int cur)
{
    arr[n] = cur;
    //base
    if (n == cnt)
    {
        Out();
        return;
    }
    //all
    for (int i = 1; i <= cnt; i++)
    {
        if (flags[i] == 0)
        {
            flags[i] = 1;
            A(n + 1, i);
            flags[i] = 0;
        }
    }
}