#include <stdio.h>
void fun(int a)
{
	int data[10000];
	int i = 0, j = 0;
	while (a > 0)
	{
		if ((a % 10) % 2 == 0)
		{
			data[i] = a % 10;
			i++;
		}
		a = a / 10;
	}
	if (i == 0)
	{
		printf("0 ");
		printf("\n");
	}
	else
	{
		for (j = 0; j < i; j++)
			printf("%d ", data[j]);
	}
	printf("\n");
}

int main()
{
	int a;
	printf("请输入一个整数：");
	while (scanf("%d", &a) != EOF)
	{
		fun(a);
	}
	return 0;
}
