#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define E 2.71828182845

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
	double a, b, c;
	while (~scanf("%lf%lf%lf", &a, &b, &c))
	{
		double lres = -12.0, res = 0.0;
		double left = 1.0 / E, right = 1e6;
		double leftn = a * left * log(left) - b * exp(-pow((left - 1.0 / E), 4)) + c;
		double rightn = a * right * log(right) - b * exp(-pow((right - 1.0 / E), 4)) + c;
		if (rightn * leftn > 0) {
			printf("No solution.\n");
			continue;
		}
		while (fabs(res - lres) > 1e-7)
		{
			lres = res;
			res = left + ((right - left) / 2);
			if (((a * res * log(res) - b * exp(-pow((res - 1.0 / E), 4)) + c) > 0))
			{
				right = res;
			}
			else {
				left = res;
			}
		}
		printf("%lf\n", res);
	}

	// fclose(stdin);
}