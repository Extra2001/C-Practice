#include <math.h>
#include <stdio.h>

double Uncertainty_A(double a[], int n)
{
    double sum = 0.0, avg;
    int i;
    for (i = 0; i < n; i++)
        sum += a[i];
    avg = sum / n, sum = 0.0;
    for (i = 0; i < n; i++)
        sum += (a[i] - avg) * (a[i] - avg);
    return sqrt(sum / (n * (n - 1)));
}

double Uncertainty(double a, double b)
{
    return sqrt(a * a + b * b);
}

double avg(double a[], int n)
{
    double sum = 0.0;
    int i;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}

int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);

    int n, i;
    double a[105], b[105], c[105], V[105], uba, ubb, ubc, res;
    scanf("%d%lf%lf%lf", &n, &uba, &ubb, &ubc);
    for (i = 0; i < n; i++)
    {
        scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
        V[i] = a[i] * b[i] * c[i];
    }
    res = avg(V, n) * sqrt(pow((Uncertainty(Uncertainty_A(a, n), uba) / avg(a, n)), 2) +
                           pow((Uncertainty(Uncertainty_A(b, n), ubb) / avg(b, n)), 2) +
                           pow((Uncertainty(Uncertainty_A(c, n), ubc) / avg(c, n)), 2));
    printf("%lf", res);
}