#include <stdio.h>
#include <string.h>

char scores[100005][505];
char tempName[505];
char laji[5];

int main()
{
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\统计上机成绩\\in3.txt", "r", stdin);
    freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\统计上机成绩\\out3.txt", "w", stdout);
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int n, m, cnt = 0, i, max = 0;
    double tmp;
    scanf("%d%d", &n, &m);
    gets(laji);
    while (n--)
    {
        gets(tempName);
        scanf("%lf", &tmp);
        gets(laji);
        int index = (int)(tmp * 100 + 1e-9);
        strcpy(scores[index], tempName);
        if (max < index) max = index;
    }
    for (i = max; cnt < m && i >= 0; i--)
    {
        if (scores[i][0] != 0)
        {
            puts(scores[i]);
            cnt++;
        }
    }
}