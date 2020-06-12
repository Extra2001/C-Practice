#include <stdio.h>
#include <string.h>

int main()
{
    char a[50] = {0};
    char b[50] = {0};

    char *ans[20], *this, *tmp;
    int len, num = 0;

    gets(a);
    gets(b);
    len = strlen(b);

    for (this = a; *this != 0; this = tmp + len)
    {
        if ((tmp = strstr(this, b)) != NULL)
        {
            // ans[num]=tmp;
            // num++;
        printf("%d-%d\n",(int)(tmp-a),(int)(tmp-a)+len-1);
        }else
        {
            return 0;
        }
        
    }
    return 0;
}