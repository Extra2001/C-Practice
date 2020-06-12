#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define N 4
#define abs(x) ((x)>=0?(x):-(x))
int gcd(int a, int b)
{
    if (a == 0 && b == 0) return 0;
    if (a == 0) return abs(b); if (b == 0) return abs(a);
    if (a<0||b<0) return gcd(abs(a), abs(b));
    if (a < b)return gcd(b, a);
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int bill[N+1], ben[N+1];
int perm[N+1], vis[N+1];
bool flg;
bool check()
{
    for (int i = 1; i <= N; i++)
        if (gcd(bill[i], ben[perm[i]]) == 1) return false;
    return flg = true;
}

void dfs(int depth)
{
    if (flg) return;
    if (depth > N) {check(); return;}
    for (int i = 1; i <= N; i++)
    {
        if (vis[i]) continue;
        perm[depth] = i; vis[i] = true;
        dfs(depth + 1);
        if (flg) return;
        vis[i] = false;
    }
    perm[depth] = 0;
}

int main()
{
    while (scanf("%d%d%d%d", bill+1, bill+2, bill+3, bill+4) != EOF)
    {
        scanf("%d%d%d%d", ben+1, ben+2, ben+3, ben+4);
        memset(perm, 0, sizeof(perm));
        memset(vis, 0, sizeof(vis));
        flg = false;
        dfs(1);
        if (flg) 
            for (int i = 1; i <= N; i++)
                printf("%dvs%d\n", bill[i], ben[perm[i]]);
        else puts("As we can't.");
    }
    return 0;
}