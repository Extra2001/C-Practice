#include <stdio.h>
#include <stdlib.h>
int dui[1000000];

int main()
{
    // freopen("./in3.txt", "r", stdin);
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in3.txt", "r", stdin);

    int n, k;
    scanf("%d%d", &n, &k);
    int tmp;
    int h = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (e - h == 0 && k > 0)
        {
            dui[e] = tmp >> 1;
            e++;
            k--;
        }
        else if (k > 0)
        {
            while (k > 0 && dui[h] > tmp)
            {
                dui[e] = dui[h] >> 1;
                e++;
                h++;
                k--;
            }
            if (k > 0)
            {
                dui[e] = tmp >> 1;
                e++;
                k--;
            }
            else
            {
                dui[e] = tmp;
                e++;
            }
        }
        else
        {
            dui[e] = tmp;
            e++;
        }
    }
    long long sum = 0;
    for (int i = h; i < e; i++)
    {
        sum += dui[i];
    }
    printf("%lld", sum);
}