#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *ReadDouble(char *a, double *dbl)
{
    while (*a != '\0' && isspace(*a))
    {
        a++;
    }
    if (sscanf(a, "%lf", dbl) != 1)
    {
        return NULL;
    }
    while (*a != '\0' && !isspace(*a))
    {
        a++;
    }
    return a;
}

char *ReadInt(char *a, int *dbl)
{
    while (*a != '\0' && isspace(*a))
    {
        a++;
    }
    if (sscanf(a, "%d", dbl) != 1)
    {
        return NULL;
    }
    while (*a != '\0' && !isspace(*a))
    {
        a++;
    }
    return a;
}
int *ReadIntArray(char *a, int n){
    int temp, *ret;
    ret = (int *)malloc(sizeof(int) * n);
    int *curr = ret;
    while ((a = ReadInt(a, &temp)) != NULL)
    {
        *curr = temp;
        curr++;
    }
    return ret;
}

double *ReadDoubleArray(char *a, int n)
{
    double temp, *ret;
    ret = (double *)malloc(sizeof(double) * n);
    double *curr = ret;
    while ((a = ReadDouble(a, &temp)) != NULL)
    {
        *curr = temp;
        curr++;
    }
    return ret;
}

int main()
{
    char *a = "22.2 44.4";
    double *d = ReadDoubleArray(a, 2);
    printf("%lf %lf", *d, *(d + 1));
}