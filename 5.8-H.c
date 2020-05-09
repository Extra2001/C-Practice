#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[10015][105];

int cmp(const void *a, const void *b)
{
    char *p1 = (char *)a;
    char *p2 = (char *)b;
    if (strlen(p1) == strlen(p2))
    {
        int i;
        for (i = 0; *(p1 + i) == *(p2 + i) && i < strlen(p1); i++)
            ;
        return *(p1 + i) - *(p2 + i);
    }
    else
    {
        return strlen(p1) - strlen(p2);
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int count = 0;
    while (gets(word[count++]) != NULL)
        ;
    qsort(word, count, sizeof(word[0]), cmp);
    for (int i = 0; i < count; i++)
    {
        if(strlen(word[i])==0){
            continue;
        }
        puts(word[i]);
    }
    // fclose(stdin);
}