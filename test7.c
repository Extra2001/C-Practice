#include <stdio.h>
#include <string.h>

int main()
{
    freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    int n, i, j, laji[30];
    scanf("%d", &n);
    gets(laji);
    for (j = 0; j < n; j++)
    {
        char a[3010] = {}, b[30] = {}, c[30] = {}, d[4010] = {};
        gets(a);
        gets(b);
        gets(c);
        int l1, l2, l3, l, sign = 0;
        l1 = strlen(b);
        l2 = strlen(c);
        l3 = strlen(a);
        l = l2 - l1;
        char *p, *q = a;
        p = strstr(a, b);
        while (p != NULL)
        {
            for (i = q - a; i < p - a; i++)
                d[i + sign * l] = a[i];
            strcat(d, c);
            q = p + l1; //跳过挖掉的原字符串
            p = strstr(p + l1 + 1, b);
            sign++;
        }
        for (i = q - a; i < l3; i++)
            d[i + sign * l] = a[i];
        printf("%s\n", d);
    }
    return 0;
}