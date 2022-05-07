#include <ctype.h>
#include <stdio.h>
#include <string.h>

char a[100000];
int hh(char h[]);
int main()
{
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    puts("let data = [");
    while (gets(a))
    {
        printf("%s,\n", a);
    }
    puts("]\nmodule.exports = { data: data }");
}