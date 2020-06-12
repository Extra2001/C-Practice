#include <stdio.h>
#include <string.h>
#include <math.h>

char can[10005] = {0};
char ref[10005] = {0};

char refCpy[10005] = {0};

double p(int n)
{
    char need[10] = {0};
    char *begin = can, *beginRef;
    double succ = 0.0, all = 0.0;
    strcpy(refCpy, ref);
    while (strlen(begin) >= n)
    {
        all++;
        strncpy(need, begin, n);
        // printf("%s %s %d\n", refCpy, need, strstr(refCpy, need));
        if ((beginRef = strstr(refCpy, need)) != NULL)
        {
            begin += n;
            memset(beginRef, 1, n);
            succ++;
        }
        else
        {
            begin++;
        }
    }
    // printf("%f",succ/all);
    return succ / all;
}

int main()
{
    int lenCan, lenRef, i;
    double BP, sum, w[5];
    gets(can);
    gets(ref);
    scanf("%lf %lf %lf %lf", w + 1, w + 2, w + 3, w + 4);

    lenCan = strlen(can);
    if (can[lenCan - 1] < 30)
    {
        can[lenCan - 1] = 0;
        lenCan--;
    }
    lenRef = strlen(ref);
    if (ref[lenRef - 1] < 30)
    {
        ref[lenRef - 1] = 0;
        lenRef--;
    }
// printf("%d %d\n",lenCan,lenRef);
    if (lenCan > lenRef)
    {
        BP = 1.0;
    }
    else
    {
        BP = exp(1 - (double)lenRef / lenCan);
    // printf("%f\n",BP);
    }


    for (i = 1, sum = 0.0; i <= 4; ++i)
    {
        sum += w[i] * log(p(i))/log(2);
        // printf("%f\n", p(i));
    }
        // printf("%f\n", BP);
    printf("%0.4f", BP * exp(sum));
}