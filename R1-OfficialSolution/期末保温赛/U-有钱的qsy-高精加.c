// 高精度加法
#include <stdio.h>
#include <string.h>
int A[105], B[105];
char c1[105], c2[105];
int main()
{
    int l1, l2, l, i;
    scanf("%s%s",c1,c2);
    l1 = strlen(c1);
    for (i = 0;i < l1;i++)
        A[l1 - i - 1] = c1[i] - '0';
    l2 = strlen(c2);
    for (i = 0;i < l2;i++)
        B[l2 - i - 1] = c2[i] - '0';
    l = l1 > l2 ? l1 : l2;
    for (i = 0;i<l;i++)
    {
        A[i] += B[i];
        if (A[i] >= 10){
            A[i] -= 10, A[i + 1]++;
            if (i + 1 >= l)l++;
        }
    }
    for (i = l - 1; i>= 0; i--)
        printf("%d",A[i]);
    printf("\n");
    return 0;
}