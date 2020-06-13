#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, x, y, k;
    while (~scanf("%d%d%d%d", &n, &x, &y, &k))
    {
        int flag = 1;
        while (flag || x < k)
        {
            x++;
            y++;
            if (y > 6)
            {
                y = 0;
            }
            if (x > n)
            {
                x = 1;
                flag = 0;
            }
        }
        switch (y)
        {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;

        default:
            break;
        }
        printf("\n");
    }

    // fclose(stdin);
}