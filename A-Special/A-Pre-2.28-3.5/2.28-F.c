#include <stdio.h>

int maxIndex(int n, int arr[]);
int main()
{
    int length, k, l, m;
    scanf("%d", &length);
    int a[length], b[length];
    int cunliang[length], zengliang[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            cunliang[i] = a[i];
        }
        else
        {
            cunliang[i] = cunliang[i - 1] + a[i] - b[i];
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            zengliang[i] = cunliang[i];
        }
        else
        {
            zengliang[i] = cunliang[i] - cunliang[i - 1];
        }
    }
    k = maxIndex(length, zengliang) + 1;
    l = maxIndex(length, cunliang) + 1;
    for (int i = length - 1; i > 0; i--)
    {
        if (cunliang[i] == 0)
        {
            m = i + 1;
        }
        else
        {
            break;
        }
    }
    printf("%d %d %d", k, l, m);
    return 0;
}
int maxIndex(int n, int arr[])
{
    int index = -1;
    int flag = -1;
    int flag1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] < arr[j])
            {
                flag = 0;
                break;
            }
            flag = 1;
        }
        if (flag == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (arr[i] == arr[j])
                {
                    flag1 = 1;
                    if (i > j)
                    {
                        index = i;
                    }
                    else
                    {
                        index = j;
                    }
                }
            }
            if (flag1 == 0)
            {
                index = i;
            }
            break;
        }
    }
    return index;
}