#include <stdio.h>

int main()
{
    int a[] = {1, 3, 5}, c;
    int *p = &a[1];
    c = *(p++);
    printf("%d %d", c, *p);
}

void bubbleSort(int a[], int n)
{
    int i, j, hold, flag;
    int swap = 0, compare = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            compare++;
            if (a[j] > a[j + 1])
            {
                swap++;
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    printf("%d %d", compare, swap);
}