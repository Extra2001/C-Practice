#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEndR(char *base);

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int k, tmp;
    int m1 = 0, m2 = 0, m3 = 0;
    while (~scanf("%d", &k))
    {
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &tmp);
            if (tmp > m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = tmp;
            }
            else if (tmp > m2)
            {
                m3 = m2;
                m2 = tmp;
            }
            else if (tmp > m3)
                m3 = tmp;
        }
        printf("%d %d %d\n", m1, m2, m3);
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}