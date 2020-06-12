// 二路有序序列的归并+二分查找，注意多组数据(非常坑！！！！！！)
#include <stdio.h>
#include <stdlib.h>
int n,m,k;
int a[10005], b[10005], c;
int s[20005];
int binsearch(int l, int r)
{
    int mid = (l + r) / 2;
    if (l == r && c != s[mid])return -1;
    if (c == s[mid] && (mid == 1 || c < s[mid-1]))return mid;
    else if (c > s[mid] || (c == s[mid] && mid > 1 && c == s[mid-1]))
        return binsearch(l,mid);
    else return binsearch(mid+1,r);
}
int main()
{
    int i,j,l = 0;
    while(scanf("%d%d%d",&n,&m,&k) != EOF) // 坑！！！！考试时一定看清题目！
    {
        for (i = 1;i<=n;i++)
            scanf("%d",&a[i]);
        for (i = 1;i<=m;i++)
            scanf("%d",&b[i]);
        /*整合两个班的成绩*/
        i = n;j = 1;l = 1;
        while (i >= 1 && j <= m)
        {
            if (a[i] > b[j])s[l++] = a[i--];
            else s[l++] = b[j++];
        }
        while (i >= 1)
            s[l++] = a[i--];
        while (j <= m)
            s[l++] = b[j++];
        l--;
        /*二分查找*/
        for (i = 1;i<=k;i++)
        {
            scanf("%d",&c);
            printf("%d%c",binsearch(1,l),i == k ? '\n' : ' ');
        }
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    
    return 0;
}