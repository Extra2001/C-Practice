# Q 数字点读机

| 难度 | 考点     |
| ---- | ---------|
| 3    | 字符数组 |

## 题目分析

先将数字的基本单词按序储存在二维字符数组中，对于输入的数字，可以每四位分成一组存入数组中，然后从高位开始逐组输出其读法。除此方法之外，也可以按数字的位数分类讨论。

## 示例代码

```c
#include <stdio.h>
#include <string.h>
#include <math.h>

char digits[15][15] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char teens[15][15] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char tens[15][15] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char units[5][15] = {"", "thousand", "million", "billion"};

void tensPrint(int x)//打印两位数
{
    if(x < 10) printf("%s", digits[x]);
    else if(x < 20) printf("%s", teens[x - 10]);
    else
    {
        int d = x / 10;
        x %= 10;
        if(x) printf("%s-%s", tens[d], digits[x]);
        else printf("%s", tens[d]);
    }
}

int hundredPrint(int x)//打印三位数
{
    if(x == 0) return 0;
    int d = x / 100;
    x %= 100;

    if(d)
    {
        printf("%s hundred", digits[d]);
        if(x)
        {
            printf(" and ");
            tensPrint(x);
        }
    }
    else if(x) tensPrint(x);

    return 1;
}


int main()
{
    long long n;
    int i, num[5], count;
    while(~scanf("%lld", &n))
    {
        memset(num, 0, sizeof(num));
        count = -1;
        if(n == 0)
        {
            printf("zero\n");
            continue;
        }

        while(n > 0)//每四位分一组
        {
            num[++count] = n % 1000;
            n /= 1000;
        }

        for(i = count; i >= 0; i--)//从高位开始逐组打印
        {
            if(i == count && num[i] > 0)
            {
                hundredPrint(num[i]);
                printf(" %s", units[i]);
            }
            else if(num[i] > 0)
            {
                printf(", ");
                hundredPrint(num[i]);
                printf(" %s", units[i]);
            }
        }
        printf("\n");
    }

    return 0;
}

```

*AUTHOR：罗梓浩*





