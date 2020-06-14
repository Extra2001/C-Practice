#include <stdio.h>
int main()
{
	int s[100];
	int i, sum;
	sum = 1;
	for (i = 0; i < 100; i++)
	{
		scanf("%d", s[i]);
	}
	for (i = 0; i < 100; i++)
	{
		sum = sum * s[i];
	}
	printf("%d", sum);
}
