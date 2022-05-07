#include <stdio.h>
#include <string.h>

int a[1000005];

int findIndex(int *base, int target, int left, int right)
{
    if (base[right] == target || left == right)
        return right;
    int mid = (left + right) / 2;
    if ((left + right) & 1)
        mid++;
    if (base[mid] < target)
        return findIndex(base, target, left, mid - 1);
    else
        return findIndex(base, target, mid, right);
}

int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\out2.txt", "w", stdout);
    // freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\阿水的二分查找\\in2.txt", "r", stdin);
    // freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\阿水的二分查找\\out2.txt", "w", stdout);
    int n, m, tmp;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        int index = findIndex(a, tmp, -1, n);
        // if (index == 0 && a[0] < tmp)
        //     printf("0\n");
        printf("%d\n", index + 1);
    }
}
