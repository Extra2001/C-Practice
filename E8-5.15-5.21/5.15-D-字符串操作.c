#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TrimEnd(char *base);

char a[100015];

char str1[1005], str2[1005];

char out[40000];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    gets(str1);
    gets(str2);
    TrimEnd(str1);
    TrimEnd(str2);
    int i;
    char *p = out;
    for (i = 0; gets(a) != NULL; i++)
    {
        char *j = strstr(a, str1);
        if (j != NULL)
        {
            j += strlen(str1);
            TrimEnd(j);
            int t = strcmp(j, str2);
            if (t != 0)
            {
                strcpy(p, j);
                p += strlen(j);
            }
        }
    }
    printf("%d\n", strlen(out));
    strcpy(p, "#END");
    puts(out);

    // fclose(stdin);
}

int TrimEnd(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}