#include <algorithm>
#include <iostream>

using namespace std;
int a[1000005];

int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\out.txt", "w", stdout);
    // freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\阿水的二分查找\\in2.txt", "r", stdin);
    // freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\阿水的二分查找\\out2.txt", "w", stdout);
    int n, m, tmp;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        int out = lower_bound(a, a + n, tmp) - a;
        printf("%d\n", n - out);
    }
    return 0;
}
