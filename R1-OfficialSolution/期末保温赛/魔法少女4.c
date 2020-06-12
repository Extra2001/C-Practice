#include <stdio.h>
int f(int x)
{
    switch(x)
    {
        case 1:case 2:case 3:
            return x;
        default:
            return f(x-1) + f(x-3);
    }
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",f(x));
    return 0;
}