#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

int in[1005], sorted[1005];

int cmp(const void *a, const void *b)
{
    int *e = (int *)a, *f = (int *)b;
    return *e - *f;
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    IN1(n);
    for (int i = 0; i < n; i++)

        IN1(sorted[i]);
    memcpy(in, sorted, n * sizeof(sorted[0]));
    qsort(sorted, n, sizeof(sorted[0]), cmp);
    
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}