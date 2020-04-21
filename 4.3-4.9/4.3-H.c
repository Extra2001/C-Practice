#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//甄医生找工作牌
int bed[2015] = { 0 };

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int x, n, a, b, c, currid, currside, i, count = 0;
	scanf("%d%d", &currid, &n);
	if (currid <= n)
	{
		currside = 0;
	}
	else
	{
		currside = 1;
	}
	bed[currid] = 1;
	while (~scanf("%d%d%d", &a, &b, &c))
	{
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		if (a == -1)
		{
			currside = !currside;
			currid = 2 * n + 1 - currid;
			if (b == 1)
			{
				currid -= c;
			}
			else
			{
				currid += c;
			}
		}
		else
		{
			if (b == 1)
			{
				currid += c;
			}
			else
			{
				currid -= c;
			}
		}
		bed[currid] = 1;
	}
	for (i = 0; i < 2 * n; i++)
	{
		if (bed[i + 1])
		{
			count++;
		}
	}
	printf("%d %d", count, currid);
	//fclose(stdin);
}