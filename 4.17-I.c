#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Read();

char s[4015], a[25], b[25];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    Read();
    if (strstr(s, a) == NULL)
    {
        printf("No Replacement!");
        return 0;
    }
    char *p = s;
    int count = 0;
    char *n = strstr(p, a);
    while (count < strlen(s))
    {
        if (p == n)
        {
            for (int i = 0; i < strlen(b); i++)
                putchar(b[i]);
            count += strlen(a);
            p += strlen(a);
            n = strstr(p, a);
            continue;
        }
        count++;
        putchar(*p);
        p++;
    }
    putchar(';');
    // fclose(stdin);
}

void Read()
{
    gets(s);
    gets(a);
    gets(b);
    for (int i = strlen(s) - 1; i >= 0; i--)
        if (s[i] == ';')
        {
            s[i] = '\0';
            break;
        }
    for (int i = strlen(a) - 1; i >= 0; i--)
        if (a[i] == ';')
        {
            a[i] = '\0';
            break;
        }
    for (int i = strlen(b) - 1; i >= 0; i--)
        if (b[i] == ';')
        {
            b[i] = '\0';
            break;
        }
}