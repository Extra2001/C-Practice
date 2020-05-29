#include <stdio.h>
struct virus
{
    int a;
    int b;
    int c;
    int sum;
};

void Swap(struct virus arr[], int low, int high)
{
    struct virus temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

int Partition(struct virus arr[], int low, int high)
{
    int base = arr[low].sum;
    while (low < high)
    {
        while (low < high && arr[high].sum >= base)
        {
            high--;
        }
        Swap(arr, low, high);
        while (low < high && arr[low].sum <= base)
        {
            low++;
        }
        Swap(arr, low, high);
    }
    return low;
}

void QuickSort(struct virus arr[], int low, int high)
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
    int n, m, i;
    scanf("%d%d\n", &n, &m);
    struct virus v[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].c);
        v[i].sum = v[i].a + v[i].b + v[i].c;
    }
    QuickSort(v, 0, n - 1);
    if (n >= m)
    {
        for (i = n - 1; i >= n - m; i--)
        {
            printf("%d %d %d\n", v[i].a, v[i].b, v[i].c);
        }
    }
    else
    {
        for (i = n - 1; i >= 0; i--)
        {
            printf("%d %d %d\n", v[i].a, v[i].b, v[i].c);
        }
    }
    return 0;
}