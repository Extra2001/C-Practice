#include <ctype.h>
#include <stdio.h>
#include <string.h>

char str[1000000];
char str1[1000000];

int main()
{
    freopen("./hh/in3.txt", "r", stdin);
    freopen("./hh/in31.txt", "w", stdout);

    while (gets(str))
    {
        puts(str);
        gets(str);
        gets(str1);
        int n = strlen(str);
        int m = strlen(str1);
        for (int i = 0; i < n; i++)
        {
            if (isupper(str[i]))
                str1[i] = toupper(str1[i]);
            else if (islower(str[i]))
                str1[i] = tolower(str1[i]);
        }
        puts(str);
        puts(str1);
    }
}