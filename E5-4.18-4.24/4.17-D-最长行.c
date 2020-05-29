#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char f[20015];
char out[20015];
int max = -1;

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    while (gets(f) != NULL)
    {
        int n = strlen(f);
        while (f[n - 1] == ' ' || f[n - 1] == '\n' || f[n - 1] == '\t' || f[n - 1] == '\r')
        {
            f[n - 1] = '\0';
            n--;
        }
        if (max <= n)
        {
            max = n;
            strcpy(out, f);
        }
    }
    printf("%d %s#END\n", max, out);

    // fclose(stdin);
}