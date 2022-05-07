#include <stdio.h>
struct bot
{
    int c;
    int w;
};

void Next(struct bot robot[], int L, int j)
{
    //	if(x == -1){
    if (robot[j].w == 1)
    { //顺时针
        if (robot[j].c + 1 == L)
        {
            robot[j].c = 0;
        }
        else
        {
            robot[j].c++;
        }
    }
    else
    { //逆时针
        if (robot[j].c - 1 < 0)
        {
            robot[j].c = L - 1;
        }
        else
        {
            robot[j].c--;
        }
    }
}
void Swap(struct bot arr[], int low, int high)
{
    struct bot temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

int Partition(struct bot arr[], int low, int high)
{
    int base = arr[low].c;
    while (low < high)
    {
        while (low < high && arr[high].c >= base)
        {
            high--;
        }
        Swap(arr, low, high);
        while (low < high && arr[low].c <= base)
        {
            low++;
        }
        Swap(arr, low, high);
    }
    return low;
}

void QuickSort(struct bot arr[], int low, int high)
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
    int n, L, t, i, j;
    scanf("%d%d%d\n", &n, &L, &t);
    struct bot robot[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &robot[i].c, &robot[i].w);
    }
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < n; j++)
        {
            Next(robot, L, j);
        }
    }
    QuickSort(robot, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d ", robot[i].c);
    }
    return 0;
}