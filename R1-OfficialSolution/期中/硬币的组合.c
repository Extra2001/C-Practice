#include <stdio.h>

#pragma GCC optimize(4)

int f(int num, int max)
{
    int thisMax = 1;
    int ans = 0;

if(num==0){
    return 1;
}

    for (thisMax = 1; thisMax <= max && thisMax <= num; thisMax <<= 1)
    {
        ans += f(num - thisMax, thisMax);
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", f(n, n));
}