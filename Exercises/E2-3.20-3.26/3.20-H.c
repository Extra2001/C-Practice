#include <math.h>
#include <stdio.h>
#include <string.h>
//弹反,反过来输出
int s[2000];
int main()
{
	long long int a = 0, b = 0, c, sum, i = 0, j, count = 0;
	int flag = 1;
	scanf("%lld", &a);
	if (a == 0)
	{
		printf("0");
		return 0;
	}
	b = a;
	if (b >= 0)
	{
		c = 0;
	}
	else
	{
		c = 1;
	}
	while (b != 0)
	{
		s[i] = b % 10;
		b /= 10;
		i++;
	}
	if (c)
	{
		printf("-");
	}
	for (j = 0; j < i; j++)
	{
		if (abs(s[j]) == 0 && flag)
		{
			continue;
		}
		else
		{
			flag = 0;
		}
		printf("%d", abs(s[j]));
	}
}