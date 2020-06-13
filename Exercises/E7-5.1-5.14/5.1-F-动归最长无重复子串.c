#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[10015];

int c[125];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    while (gets(a) != NULL)
    {
        char *p = a;
        int n = strlen(p);
        int count = 0, max = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 'a' || a[i] > 'z')
                continue;
            if (c[a[i]])
            {
                p = strchr(p, a[i]);
                memset(c, 0, sizeof(c));
                int j;
                for (j = 0; p + j != a + i; j++)
                {
                    c[*(p + j)] = 1;
                }
                p++;
                if (count > max)
                    max = count;
                count = j;
            }
            else
            {
                c[a[i]] = 1;
                count++;
            }
        }
        if (count > max)
            max = count;
        printf("%d\n", max);
        memset(c, 0, sizeof(c));
    }
}