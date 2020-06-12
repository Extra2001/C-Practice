// 去年的古风排版，非常容易PE或者WA
// 注意事项：1. 读入的时候如果用gets最好判断一下'\r'(本题数据比较友好，实测没有\r卡大家)
// 2. 最左边一列没摆满务必补齐空格，实现方式有很多，可以在数组里直接补上空格，或者是二重循环一个一个字符输出，然后遇到\0空字符就输出空格
#include <stdio.h>
#include <string.h>
char gf[1002][1002];
char txt[1005];
int l, k;
void display()
{
    int i;
    for (i = 0; i < k; i++)
        printf("%s\n", gf[i]);
}
int main()
{
    int i, j, p = 0;
    char c;
    scanf("%d", &k);
    while (getchar() != '\n');
    gets(txt);
    l = strlen(txt);
    if (txt[l - 1] == '\r') txt[--l] = 0;
    for (j = l / k + (l % k != 0) - 1, i = 0; p < l; p++)
    {
        gf[i][j] = txt[p];
        i++;
        if (i == k)i = 0, j--;
    }
    for (i = 0; i < k; i++)
        if (gf[i][j] == 0)gf[i][j] = ' ';
    for (i = 0; i < k; i++)
        printf("%s\n", gf[i]);
    return 0;
}