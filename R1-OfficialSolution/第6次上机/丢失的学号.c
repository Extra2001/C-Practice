#include <stdio.h>
#include <string.h>

int main()
{
    int d;
    char s[100] = {0};
    scanf("%s", s);
    if (strcmp(s, "ShiE") == 0)
    {
        d = 73;
    }
    else if (strcmp(s, "FengRu") == 0)
    {
        d = 74;
    }
    else if (strcmp(s, "ShiJia") == 0)
    {
        d = 75;
    }
    else if (strcmp(s, "ShouE") == 0)
    {
        d = 76;
    }
    else if (strcmp(s, "ZhiZhen") == 0)
    {
        d = 77;
    }
    else if (strcmp(s, "ZhiXing") == 0)
    {
        d = 79;
    }

    printf("193%d299", d);
}