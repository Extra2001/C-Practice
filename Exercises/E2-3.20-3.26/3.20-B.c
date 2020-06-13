#include <stdio.h>
#include <math.h>
//最萌身高差
int s[2000];
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (j = 0; j < n; j++)
    {
        for (i = j + 1; i < n; i++)
        {
            if (abs(s[j] - s[i]) > 10)
            {
                if ((s[i] & 1) == (s[j] & 1)) {
                    printf("%d %d\n", j + 1, i + 1);
                }
            }
        }
    }
    return 0;
}