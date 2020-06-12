#include <stdio.h>
#include <string.h>

int is(char *ss, int l, int r)
{
    while (r > l)
    {
        if (ss[l] != ss[r])
        {
            return 0;
        }
        r--;
        l++;
    }

    return 1;
}

int main()
{
    char s[300] = {0};
    int q, i, j, k, n, len;

    scanf("%d", &q);
    while (q--)
    {
        scanf("%s", s);
        len = strlen(s);
        n = 1;
        for (i = 0; i < len; ++i)
        {
            for (j = i + n; j < len; ++j)
            {
                if (is(s, i, j))
                {
                    n = j - i+1;
                }
            }
        }
        printf("%d\n", n);
    }
}