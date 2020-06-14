#include <stdio.h>
int main()
{
	int i, n = 20;
	double sum = 0.0, f = 1.0;
	for (i = 1; i <= n; i++)
	{
		f = f * i;
		sum = sum + f;
	}
	printf("阶乘之和为：%.0lf", sum);
	return 0;
}
