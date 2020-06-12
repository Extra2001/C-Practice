#include <stdio.h>
typedef long long ll;
#define MAXN 105
int a[MAXN];
ll S = -1; int start, end;
void solve(int l, int r) // [l, r]
{
    if (l > r) return;
    int mid = (l + r) >> 1;
    ll suml = 0, sumr = 0, sum = 0;
    int head = mid, tail = mid;
    for (int i = mid - 1; i >= l; i--)
    {
        sum += 1LL * a[i];
        if (sum >= suml) suml = sum, head = i;
    }
    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += 1LL * a[i];
        if (sum >= sumr) sumr = sum, tail = i;
    }
    ll smax = a[mid] + suml + sumr;
    if (smax > S) {S = smax; start = head; end = tail;}
    else if (smax == S) {
        if (tail - head > end - start) start = head, end = tail;
    }
    solve(l, mid-1);
    solve(mid+1, r);
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        S = -1; start = end = 0;
        solve(1, n);
        if (S < 0) puts("I\'m hungry!");
        else printf("%lld %d %d\n", S, start, end);

    }
    return 0;
}