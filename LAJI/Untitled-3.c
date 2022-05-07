#include <stdio.h>
#include <string.h>

int times[10000];

int hostWin(char host, char now)
{
    if (host == 'A' && now == 'C')
        return 1;
    if (host == 'B' && now == 'A')
        return 1;
    if (host == 'C' && now == 'B')
        return 1;
    return 0;
}

int main()
{
    int host, now;
    char a, b;
    scanf("%d", &host);
    int cnt = 1;
    while (~scanf("%d %c %c", &now, &a, &b))
    {
        cnt++;
        times[host]++, times[now]++;
        if (!hostWin(a, b))
            host = now;
    }
    printf("%04d %d", host, times[host]);
}