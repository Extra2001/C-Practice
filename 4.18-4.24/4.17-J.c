#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct HashElem
{
    int key;
    int value;
} Hash;
Hash Table[1005] = {0};
int a[1005] = {0};
int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n, i, tmp, maxkey, maxvalue;
    while (~scanf("%d%d", &m, &n))
    {
        memset(Table, 0, sizeof(Table));
        maxkey = maxvalue = 0;
        int top = 0;
        for (i = 0; i < m; i++)
        {
            scanf("%d", &tmp);
            int flag = 1;
            for (int j = 0; j <= top; j++)
            {
                if (Table[j].key == tmp)
                {
                    Table[j].value++;
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                Table[top].key = tmp;
                Table[top].value = 1;
                top++;
            }
        }
        for (int i = 0; i < top; i++)
        {
            if (Table[i].value > maxvalue)
            {
                maxvalue = Table[i].value;
                maxkey = Table[i].key;
            }
            else if (Table[i].value == maxvalue)
                if (maxkey < Table[i].key)
                    maxkey = Table[i].key;
        }
        printf("%d ", maxkey);
        memset(a, 0, sizeof(a));
        maxkey = maxvalue = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            a[tmp]++;
        }
        for (i = 1; i <= 1000; i++)
        {
            if (a[i] >= maxvalue)
            {
                maxvalue = a[i];
                maxkey = i;
            }
        }
        printf("%d", maxkey);
        printf("\n");
    }

    // fclose(stdin);
}