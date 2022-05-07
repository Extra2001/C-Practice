#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEndR(char *base);

char str[3015], old[30], new[30], newstr[3015];
char laji[5];
int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\out2.txt", "w", stdout);
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\写错的名字\\in6.txt", "r", stdin);
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\写错的名字\\out6.txt", "w", stdout);
    int n;
    scanf("%d", &n), gets(laji); // scanf之后记得gets
    for (int i = 0; i < n; i++)
    {
        gets(str), gets(old), gets(new);
        TrimEndR(str), TrimEndR(old), TrimEndR(new);
        int strL = strlen(str), oldL = strlen(old), newL = strlen(new), cnt = 0;
        for (char *p = str; p < str + strL; p += oldL)
        {
            char *n = strstr(p, old);
            if (n == NULL)
            {
                for (; p < str + strL; p++, cnt++)
                    newstr[cnt] = *p;
                break;
            }
            for (; p < n; p++, cnt++)
                newstr[cnt] = *p;
            for (int i = 0; i < newL; i++, cnt++)
                newstr[cnt] = new[i];
        }
        newstr[cnt] = '\0';
        puts(newstr);
    }
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}