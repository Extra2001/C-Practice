#include <stdio.h>
int main()
{
	int m, n, i;
	printf("请输入m,n的值：");
	scanf("%d %d", &m, &n);
	printf("能被3整除但不能被5整除的数有：");
	printf("\n");
	for (i = m; i < n; i++)
	{
		if ((i % 3 == 0) && (i % 5 != 0))
			printf("%d ", i);
	}
}
