#include <stdio.h>
#include <stdlib.h>
int dui[1000000];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int tmp;
    int head = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (end - head == 0 && k > 0)
        {
            dui[end] = tmp >> 1;
            end++;
            k--;
        }
        else if (k > 0)
        {
            while (k > 0 && dui[head] > tmp)
            {
                dui[end] = dui[head] >> 1;
                end++;
                head++;
                k--;
            }
            if (k > 0)
            {
                dui[end] = tmp >> 1;
                end++;
                k--;
            }
            else
            {
                dui[end] = tmp;
                end++;
            }
        }
        else
        {
            dui[end] = tmp;
            end++;
        }
    }
    long long sum = 0;
    for (int i = head; i < end; i++)
    {
        sum += dui[i];
    }
    printf("%lld", sum);
}