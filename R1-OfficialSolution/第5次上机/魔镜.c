#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_LETTER(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

char str[114520] = {0};
int L[100000] = {0};
int R[100000] = {0};

char toUpper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c + ('A' - 'a');
    }
    else
    {
        return c;
    }
}

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - ('A' - 'a');
    }
    else
    {
        return c;
    }
}

void backPrint(int from, int to)
{
    int i;
    for (i = to; i >= from; --i)
    {
        switch (str[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            putchar(toUpper(str[i]));
            break;
        default:
            putchar(toLower(str[i]));
            break;
        }
    }
}

int main()
{
    int n, letter, s, len, i, inLetter, j;
    scanf("%d", &n);
    while (getchar() != '\n')
        ;
    for (s = 0; s < n; ++s)
    {
        gets(str);
        len = strlen(str);
        letter = 0, inLetter = 0;
        for (i = 0; i < len; ++i)
        {

            if (IS_LETTER(str[i]) && inLetter == 0)
            {
                inLetter = 1;
                L[letter] = i;
            }

            if (!IS_LETTER(str[i]) && inLetter == 1)
            {
                inLetter = 0;
                R[letter] = i - 1;
                letter++;
            }
        }
        if (inLetter)
        {
            R[letter] = i;
            letter++;
        }
        printf("Case %d:", s + 1);
        for (i = 0, j = 0; i < len; ++i)
        {
            if (L[j] == i && j < letter)
            {
                backPrint(L[j], R[j]);
                i = R[j];
                j++;
            }
            else
            {
                putchar(str[i]);
            }
        }
        putchar('\n');
    }
}