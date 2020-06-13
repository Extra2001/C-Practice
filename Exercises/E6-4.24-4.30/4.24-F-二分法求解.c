#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define E 2.71828182845
double a, b, c;

double f(double x)
{
	return a * x * log(x) - b * exp(-pow((x - 1.0 / E), 4)) + c;
}

int main()
{
	// freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
	while (~scanf("%lf%lf%lf", &a, &b, &c))
	{
		int isasc = 0;
		if (a > 0 || b > 0)
		{
			isasc = 1;
		}
		double lres = -12.0, res = 0.0;
		double left = 1.0 / E, right = 1e6;
		if ((f(left) * f(right)) > 0)
		{
			printf("No solution.\n");
			continue;
		}
		while (fabs(res - lres) > 1e-8)
		{
			lres = res;
			res = left + ((right - left) / 2);
			if (f(res) > 0)
			{
				if (isasc)
				{
					right = res;
				}
				else {
					left = res;
				}
			}
			else
			{
				if (isasc)
				{
					left = res;
				}
				else {
					right = res;
				}
			}
		}
		printf("%lf\n", res);
	}

	// fclose(stdin);
}