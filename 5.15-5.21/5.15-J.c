#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char drawing[1000][1000];

void drawOne(int x, int y);
void OutPut();

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int r, l;
    scanf("%d%d", &r, &l);
    memset(drawing, 0, sizeof(drawing));
    int curr1 = 0, curr2 = 2;
    int curc = 2;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (j & 1)
                drawOne(curr2, curc);
            else
                drawOne(curr1, curc);
            curc += 6;
        }
        curr1 += 4;
        curr2 += 4;
        curc = 2;
    }
    OutPut();
    // fclose(stdin);
}

void drawOne(int x, int y)
{
    //PREPARE
    for (int i = 0; i < x + 5; i++)
        for (int j = 0; j < y + 6; j++)
            if (drawing[i][j] == '\0')
                drawing[i][j] = ' ';
    //LINE1
    drawing[x][y] = drawing[x][y + 4] = '+';
    drawing[x][y + 1] = drawing[x][y + 2] = drawing[x][y + 3] = '-';
    //LINE2
    drawing[x + 1][y - 1] = '/';
    drawing[x + 1][y + 5] = '\\';
    //LINE3
    drawing[x + 2][y - 2] = drawing[x + 2][y + 6] = '+';
    //LINE4
    drawing[x + 3][y - 1] = '\\';
    drawing[x + 3][y + 5] = '/';
    //LINE5
    drawing[x + 4][y] = drawing[x + 4][y + 4] = '+';
    drawing[x + 4][y + 1] = drawing[x + 4][y + 2] = drawing[x + 4][y + 3] = '-';
}

void OutPut()
{
    for (int i = 0; strlen(drawing[i]); i++)
        puts(drawing[i]);
}