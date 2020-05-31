#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    // for (int i = 100; i < 1000; i++)
    // {
    //     int a = i % 10, b = (i / 10) % 10, c = (i / 100) % 10;
    //     if (a == b || a == c || b == c)
    //         continue;
    //     if (a == 0 || b == 0 || c == 0)
    //         continue;
    //     for (int j = i + 1; j < 1000; j++)
    //     {
    //         int d = j % 10, e = (j / 10) % 10, f = (j / 100) % 10;
    //         if (d == e || e == f || f == d)
    //             continue;
    //         if (d == 0 || e == 0 || f == 0)
    //             continue;
    //         if (d == a || d == b || d == c || e == a || e == b || e == c || f == a || f == b || f == c)
    //             continue;
    //         for (int k = j + 1; k < 1000; k++)
    //         {
    //             int x = k % 10, y = (k / 10) % 10, z = (k / 100) % 10;
    //             if (x == y || y == z || z == x)
    //                 continue;
    //             if (x == 0 || y == 0 || z == 0)
    //                 continue;
    //             if (x == a || x == b || x == c || x == d || x == e || x == f || y == a || y == b || y == c || y == d || y == e || y == f || z == a || z == b || z == c || z == d || z == e || z == f)
    //                 continue;
    //             double m = (double)i, n = (double)j, t = (double)k;
    //             if (fabs((n / m) - 2.0) < fabs(1e-10) && fabs((t / m) - 3.0) < fabs(1e-10))
    //                 printf("%d %d %d\n", i, j, k);
    //         }
    //     }
    // }
    printf("192 384 576\n");
    printf("219 438 657\n");
    printf("273 546 819\n");
    printf("327 654 981");
    // fclose(stdin);
}