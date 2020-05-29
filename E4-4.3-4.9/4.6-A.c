#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, h, w, yc4, cc4, m5, cc;
    while (scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h) != EOF)
    {
        if (10000000 * a + 1000000 * b + 100000 * c + 10000 * d + 1000 * e + 100 * f + 10 * g + h <= 15821004)
        {
            if (e == 0 && f == 1)
            {
                e = 1;
                f = 3;
                d = d - 1;
            }
            else if (e == 0 && f == 2)
            {
                e = 1;
                f = 4;
                d = d - 1;
            }
            yc4 = (c * 10 + d) / 4;
            cc4 = (10000000 * a + 1000000 * b + 1000 * e + 100 * f + 10 * g + h) / 4;
            cc = (10000000 * a + 1000000 * b + 1000 * e + 100 * f + 10 * g + h);
            m5 = 13 * (10 * e + f + 1) / 5;
            w = ((c * 10 + d) + yc4 + cc4 - 2 * cc + m5 + 10 * g + h + 2) % 7;
            if (w <= 0)
            {
                w = w + 7;
            }
            if (w == 1)
            {
                printf("Mon\n");
            }
            else if (w == 2)
            {
                printf("Tue\n");
            }
            else if (w == 3)
            {
                printf("Wed\n");
            }
            else if (w == 4)
            {
                printf("Thu\n");
            }
            else if (w == 5)
            {
                printf("Fri\n");
            }
            else if (w == 6)
            {
                printf("Sat\n");
            }
            else if (w == 7)
            {
                printf("Sun\n");
            }
        }

        else if (10000000 * a + 1000000 * b + 100000 * c + 10000 * d + 1000 * e + 100 * f + 10 * g + h >= 15821015)
        {
            if (e == 0 && f == 1)
            {
                e = 1;
                f = 3;
                d = d - 1;
            }
            else if (e == 0 && f == 2)
            {
                e = 1;
                f = 4;
                d = d - 1;
            }
            yc4 = (c * 10 + d) / 4;
            cc4 = (10000000 * a + 1000000 * b + 1000 * e + 100 * f + 10 * g + h) / 4;
            cc = (10000000 * a + 1000000 * b + 1000 * e + 100 * f + 10 * g + h);
            m5 = 13 * (10 * e + f + 1) / 5;
            w = ((c * 10 + d) + yc4 + cc4 - 2 * cc + m5 + 10 * g + h - 1) % 7;
            if (w <= 0)
            {
                w = w + 7;
            }
            if (w == 1)
            {
                printf("Mon\n");
            }
            else if (w == 2)
            {
                printf("Tue\n");
            }
            else if (w == 3)
            {
                printf("Wed\n");
            }
            else if (w == 4)
            {
                printf("Thu\n");
            }
            else if (w == 5)
            {
                printf("Fri\n");
            }
            else if (w == 6)
            {
                printf("Sat\n");
            }
            else if (w == 7)
            {
                printf("Sun\n");
            }
        }
        else
        {
            printf("Nonexistent date!\n");
        }
    }
    return 0;
}