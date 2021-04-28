#include <stdio.h>
#include <stdlib.h>

typedef struct hh
{
    char data[32325];
    int flag;
} cp22;

int main()
{
    cp22 *arr = malloc(sizeof(cp22) * 200000);
    cp22 *arr1 = malloc(sizeof(cp22) * 200000);
    cp22 *arr2 = malloc(sizeof(cp22) * 200000);
    cp22 *arr3 = malloc(sizeof(cp22) * 200000);
    cp22 *arr4 = malloc(sizeof(cp22) * 200000);
    cp22 *arr5 = malloc(sizeof(cp22) * 200000);
    cp22 *ar6r = malloc(sizeof(cp22) * 200000);
    cp22 *arr7 = malloc(sizeof(cp22) * 200000);
    cp22 *ar8r = malloc(sizeof(cp22) * 200000);
    cp22 *arr9 = malloc(sizeof(cp22) * 200000);
    printf("%d %d %d %d %d %d %d %d %d", arr, arr1, arr2, arr3, arr4, arr5, ar6r, arr7, ar8r, arr9);
    int sum = 0;
    for (int i = 0; i < 200000; i++)
    {
        arr[i].flag = i;
        arr1[i].flag = i;
        arr2[i].flag = i;
        arr3[i].flag = i;
        arr4[i].flag = i;
        // arr5[i].flag = i;

        sum += arr[i].flag;
        sum += arr1[i].flag;
        sum += arr2[i].flag;
        sum += arr3[i].flag;
        sum += arr4[i].flag;
        // sum += arr5[i].flag;

    }
    getchar();
    return 0;
}
