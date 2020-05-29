#include <stdio.h>
unsigned long c[4000000];
void Swap(unsigned long arr[], int low, int high)
{
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

int Partition(unsigned long arr[], int low, int high)
{
    int base = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= base)
        {
            high--;
        }
        Swap(arr, low, high);
        while (low < high && arr[low] <= base)
        {
            low++;
        }
        Swap(arr, low, high);
    }
    return low;
}

void QuickSort(unsigned long arr[], int low, int high)
{
    if (low < high)
    {
        int base = Partition(arr, low, high);
        QuickSort(arr, low, base - 1);
        QuickSort(arr, base + 1, high);
    }
}

int main()
{
    int m, n, i, j, p, tmp;
    unsigned long t;
    scanf("%d%d\n", &n, &m);
    p = n * n;
    unsigned long a[n], o[m];
    for (i = 0; i < n; i++)
    {
        scanf("%lu", &a[i]);
    }
    tmp = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%lu", &t);
        for (j = 0; j < n; j++)
        {
            c[tmp + j] = a[j] + t;
        }
        tmp += n;
    }
    QuickSort(c, 0, p - 1);
    for (i = 0; i < m; i++)
    {
        scanf("%lu", &t);
        for (j = 0; j < p; j++)
        {
            if (c[j] >= t)
            {
                o[i] = p - j;
                break;
            }
            if (j == 0)
            {
                if (t > c[p - 1])
                {
                    o[i] = 0;
                    break;
                }
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        printf("%d\n", o[i]);
    }
}