#include <stdio.h>
#include <string.h>
char big(char a)
{
    if (!isupper(a))
        a = a + 'A' - 'a';
    return a;
}
int main()
{
    
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\out2.txt", "w", stdout);
    int len, i, n, num;
    scanf("%d", &n);
    getchar();
    getchar();
    char str[10005] = {0}, *p, *st;
    while (gets(str) != NULL)
    {
        num = 0;
        p = strchr(str, '_');
        if (p == NULL)
        {
            str[0] = big(str[0]);
            printf("%s\n", str);
        }
        else if (p == &str[1])
        {
            str[2] = big(str[2]);
            printf("%s\n", &str[2]);
        }
        else
        {
            str[0] = big(str[0]);
            st = str;
            while ((p = strchr(st, '_')) != NULL)
            {
                if (isalpha(*(p + 1)))
                    *(p + 1) = big(*(p + 1));
                st = p + 1;
            }
            for (i = 0; str[i] != '\0'; i++)
                if (str[i] != '_')
                    printf("%c", str[i]);
            printf("\n");
        }
    }
    return 0;
}