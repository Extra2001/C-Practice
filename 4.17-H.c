#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[120000];

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (getchar() != '\n')
        ;
    for (int i = 0; i < n; i++)
    {
        gets(a);
        printf("Case #%d: ", i + 1);
        char word[50];
        int length = strlen(a);
        int count = 0;
        for (int j = 0; j < length; j++)
        {
            if (!((word[count] = tolower(a[j])) >= 'a' && word[count] <= 'z'))
            {
                for (int k = count - 1; k >= 0; k--)
                {
                    if (word[k] == 'a' || word[k] == 'e' || word[k] == 'i' || word[k] == 'o' || word[k] == 'u')
                        printf("%c", toupper(word[k]));
                    else
                        printf("%c", word[k]);
                }
                printf("%c", word[count]);
                memset(word, 0, sizeof(word));
                count = -1;
            }
            count++;
        }
        printf("\n");
    }

    // fclose(stdin);
}