#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
char s1[MAX_LEN + 5], s2[MAX_LEN + 5];
int a[MAX_LEN + 5], b[MAX_LEN + 5], c[MAX_LEN + 5];
int main()
{
    int l1,l2,l = 0,i,j,flg;
    char op;
    scanf("%s%s",s1,s2);
    l1 = strlen(s1);l2 = strlen(s2);
    for (i = 0;i<l1;i++)
        a[l1 - i - 1] = s1[i] - '0';//反序存储，思考l1 - i - 1怎么来的
    for (i = 0;i<l2;i++)
        b[l2 - i - 1] = s2[i] - '0';
    /*先比较大小*/
    flg = 0;//两个数的大小关系，1表示A>B；-1表示A<B
    //如果A < B，竖式运算应当做B-A，结果加负号。
    if (l1 > l2)flg = 1;
    else if (l1 < l2)flg = -1;
    else {//l1 == l2
        for (i = 0;i<l1;i++)
        {
            if (s1[i] < s2[i]){flg = -1;break;}
            else if (s1[i] > s2[i]){flg = 1;break;}
        }
    }
    //开始做减法
    if (flg == 0)l = 1;//A == B的情况
    else{
        l = l1 > l2 ? l1 : l2;//被减数的长度应该是两数长度中较大的值
        for (i = 0;i<l;i++)
        {
            if (flg == 1)c[i] += a[i] - b[i];//A - B
            else c[i] += b[i] - a[i];//B - A
            while (c[i] < 0)
            {
                c[i] += 10, c[i+1] -= 1;//退位，或称借位
            }
        }
        while (c[l - 1] == 0)l--;//过滤由减法生成的前导零（e.g. 1000 - 999）
    }
    if (flg == -1)printf("-");//如果做的是B-A，结果应有负号
    //输出结果，要把反序存储的结果c再次反序
    for (i = l - 1; i >= 0; i--)
    {
        printf("%d",c[i]);
    }
    printf("\n");
    return 0;
}