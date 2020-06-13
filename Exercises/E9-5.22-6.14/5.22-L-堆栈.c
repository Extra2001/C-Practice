#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

int hao[100015];
int rudStack[100015] = {0}, huaStack[100015] = {0};

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    char tmp, last = 0;
    int rud = 0, hua = 0;
    int i;
    for (i = 1; ~scanf("%c", &tmp); i++)
    {
        switch (tmp)
        {
        case '(':
            rudStack[rud++] = i;
            break;
        case ')':
            if ((i != 1 && last == '{') || rud <= 0)
            {
                printf("NO");
                goto end;
            }
            else
            {
                hao[i] = rudStack[--rud];
                hao[rudStack[rud]] = i;
            }
            break;
        case '{':
            huaStack[hua++] = i;
            break;
        case '}':
            if ((i != 1 && last == '(') || hua <= 0)
            {
                printf("NO");
                goto end;
            }
            else
            {
                hao[i] = huaStack[--hua];
                hao[huaStack[hua]] = i;
            }
            break;
        default:
            i--;
            break;
        }
        last = tmp;
    }
    if (rud == 0 && hua == 0)
    {
        for (int j = 1; j < i; j++)
        {
            printf("%d\n", hao[j]);
        }
    }
    else
    {
        printf("NO");
    }
end:;
    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}