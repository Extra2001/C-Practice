// 判断质数
#include <stdio.h>
#include <math.h>
int main()
{
    int n,n0,i,flg = 1;
    scanf("%d",&n);
    n0 = (int)(sqrt(n) + 1);
    for (i = 2;i<n0;i++){
        if (n % i == 0){
            flg = 0;break;
        }
    }
    printf("%d\n",flg);
    return 0;
}