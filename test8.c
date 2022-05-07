#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int map[5][5];
int main()
{
    freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    int cnt = 0;
    char tmp;
    while (~scanf("%c", &tmp))
    {
        if (isdigit(tmp))
        {
            cnt++;
            int inttmp = tmp - '0' - 1;
            if (cnt & 1)
                map[inttmp / 3][inttmp % 3] = 1;
            else
                map[inttmp / 3][inttmp % 3] = 2;
        }
    }

    int out = 0;
    for (int i = 0; i < 3; i++)
        if ((map[i][0] == map[i][1]) && (map[i][0] == map[i][2]))
            if (map[i][0])
                out = map[i][0];
    for (int i = 0; i < 3; i++)
        if ((map[0][i] == map[1][i]) && (map[0][i] == map[2][i]))
            if (map[0][i])
                out = map[0][i];
    if ((map[0][0] == map[1][1]) && (map[0][0] == map[2][2]))
        if (map[0][0])
            out = map[0][0];
    if ((map[0][2] == map[1][1]) && (map[0][2] == map[2][0]))
        if (map[0][2])
            out = map[0][2];

    if (out == 1)
        printf("xiaoa wins.");
    else if (out == 2)
        printf("uim wins.");
    else
        printf("drew.");
}