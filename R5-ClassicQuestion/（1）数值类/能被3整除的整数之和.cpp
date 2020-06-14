#include <stdio.h>
int main()
{
	int m, n, i, sum;
	sum = 0;
	printf("请输入m和n的值：");
	scanf("%d %d", &m, &n);
	printf("m,n之间能被3整除的整数之和为：");
	for (i = m; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			sum = sum + i;
		}
	}
	printf("%d", sum);
	return 0;
}
