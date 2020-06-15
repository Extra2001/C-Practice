#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

int stack[1005];
char tmp[1005];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int stackTop = 0;
    while (gets(tmp) != NULL)
    {
        int cnt = 1;
        char *p = tmp;
        while (*p == '0' || *p == '1')
        {
            if (*p == '0')
            {
                if (stackTop == 0)
                    printf("Stack Empty!\n");
                else
                    printf("%d\n", stack[--stackTop]);
            }
            else if (*p == '1')
            {
                stack[stackTop++] = cnt;
            }
            cnt++;
            p++;
        }
        if (stackTop != 0)
        {
            int i = 0;
            while (i < stackTop)
            {
                printf("%d", stack[i]);
                i++;
            }
            putchar('\n');
        }
        else
            printf("Stack Empty!\n");
        stackTop = 0;
    }
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}