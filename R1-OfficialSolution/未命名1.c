#include <stdio.h>
#include <string.h>
int isSpace(char c);
int main()
{
    char arr_1[1000], arr_2[1000];
    char *in_line = arr_1, *longest = arr_2, *temp;
    int max_len = 0, len = 0;
    while (fgets(in_line, 1000, stdin) != NULL)
    {
        for (len = strlen(in_line); len > 0 && isSpace(in_line[len - 1]); len--)
        {
            in_line[len - 1] = 0;
        }
        if (len >= max_len)
        {
            max_len = len;
            temp = in_line;
            in_line = longest;
            longest = temp;
        }
    }
    printf("%d %s#END", max_len, longest);
    return 0;
}
int isSpace(char c)
{
    return (c == ' ') || (c == '\n') || (c == '\t') || (c == '\r');
}