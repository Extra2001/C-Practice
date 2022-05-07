#include <stdio.h>

int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    long long a, b = 0;
    scanf("%lld", &a);
    for (long long i = 2; i <= a; i += 1)
    {
        if (a % i == 0)
        {
            printf("%lld", a / i);
            break;
        }
    }
}
