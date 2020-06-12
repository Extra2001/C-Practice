#include <stdio.h>
typedef struct
{
    int x,y;
    int v,p;
}prize;
prize p[101][101], final;
int n;
int cmp(prize a,prize b)
{
    if (a.v > b.v)return 1;
    else if (a.v == b.v && a.p < b.p)return 1;
    return 0;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for (i = 1;i<=n;i++)
    for (j = 1;j<=n;j++)
    {
        scanf("%d",&p[i][j].v);
    }
    for (i = 1;i<=n;i++)
    for (j = 1;j<=n;j++)
    {
        scanf("%d",&p[i][j].p);
        p[i][j].x = i;
        p[i][j].y = j;
    }
    final = p[1][1];
    for (i = 1;i<=n;i++)
    for (j = 1;j<=n;j++)
    {
        if (cmp(p[i][j], final))final = p[i][j];
    }
    printf("%d %d\n",final.x,final.y);
    return 0;
}