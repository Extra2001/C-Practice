#include <stdio.h>
#include <string.h>

char a[2005];

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    while (gets(a))
    {
        int n = strlen(a);
        while (a[n - 1] == '\r')
            a[n - 1] = '\0', n--;
        for (int i = n - 1; i >= 0; i--)
        {
            switch (a[i])
            {
            case '\\':
                a[i] = '/';
                break;
            case '/':
                a[i] = '\\';
                break;
            case '{':
                a[i] = '}';
                break;
            case '}':
                a[i] = '{';
                break;
            case '[':
                a[i] = ']';
                break;
            case ']':
                a[i] = '[';
                break;
            case '(':
                a[i] = ')';
                break;
            case ')':
                a[i] = '(';
                break;
            case 'p':
                a[i] = 'q';
                break;
            case 'q':
                a[i] = 'p';
                break;
            case 'b':
                a[i] = 'd';
                break;
            case 'd':
                a[i] = 'b';
                break;
            case '<':
                a[i] = '>';
                break;
            case '>':
                a[i] = '<';
                break;
            }
            putchar(a[i]);
        }
        putchar('\n');
    }
}