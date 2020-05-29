#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1005];
int CompareFromLowToHigh(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); //升序
}
int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int count = 0;
    while (~scanf("%d", &a[count]))
    {
        count++;
    }
    qsort(a, count, sizeof(a[0]), CompareFromLowToHigh);
    for (int i = 0; i < count;i++){
        printf("%d ", a[i]);
    }

    // fclose(stdin);
}