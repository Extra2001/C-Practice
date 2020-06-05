#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//最大限度都在这里了，如果MAX大于int还需要把int改成long long
#define MAX 10005
#define INF 1e100

typedef struct aa
{
    double x, y;
} Point;

typedef struct bb
{
    Point points[MAX];
    int cnt;
} Map;

Map map;

void mapInit()
{
    memset(&map, 0, sizeof(map));
    map.cnt = 0;
}

void mapAdd(double x, double y)
{
    Point tmp;
    tmp.x = x;
    tmp.y = y;
    map.points[map.cnt++] = tmp;
}

int isOnline(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double tmp = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if ((fabs(tmp) < 1e-8) && ((x0 - x1) * (x0 - x2) <= 0) && ((y0 - y1) * (y0 - y2) <= 0))
        return 1;
    else
        return 0;
}

int isIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double tmp = (x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3);
    if (tmp != 0)
    {
        double r = ((y1 - y3) * (x4 - x3) - (x1 - x3) * (y4 - y3)) / tmp;
        double s = ((y1 - y3) * (x2 - x1) - (x1 - x3) * (y2 - y1)) / tmp;
        if ((r >= 0) && (r <= 1) && (s >= 0) && (s <= 1))
            return 1;
    }
    return 0;
}

int isInner(double x, double y)
{
    double minX = INF;
    for (int i = 0; i < map.cnt - 1; i++)
    {
        if (minX > map.points[i].x)
            minX = map.points[i].x;
    }
    double line1x = x, line1y = y, line2x = minX - 10, line2y = y;

    int cnt = 0;
    for (int i = 0; i < map.cnt - 1; i++)
    {
        double mapX1 = map.points[i].x, mapY1 = map.points[i].y, mapX2 = map.points[i + 1].x, mapY2 = map.points[i + 1].y;
        //如果边界不算的话把这改成0就行了
        if (isOnline(x, y, mapX1, mapY1, mapX2, mapY2))
            return 1;
        if (fabs(mapY2 - mapY1) < 1e-8)
            continue;
        if (isOnline(mapX1, mapY1, line1x, line1y, line2x, line2y))
        {
            if (mapY1 > mapY2)
                cnt++;
        }
        else if (isOnline(mapX2, mapY2, line1x, line1y, line2x, line2y))
        {
            if (mapY1 < mapY2)
                cnt++;
        }
        else if (isIntersect(mapX1, mapY1, mapX2, mapY2, line1x, line1y, line2x, line2y))
        {
            cnt++;
        }
    }
    if (cnt % 2 == 1)
        return 1;
    return 0;
}

int main()
{
    freopen("C:\\Users\\Lenovo\\Desktop\\测试\\1.in", "r", stdin);
    mapInit();
    int m, n;
    scanf("%d%d", &m, &n);
    int tmp1, tmp2;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        mapAdd(tmp1, tmp2);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        if (isInner(tmp1, tmp2))
            printf("YES\n");
        else
            printf("NO\n");
    }
}