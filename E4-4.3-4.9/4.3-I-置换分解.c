#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//置换的分解
int a[105];

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int n, p;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i - 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == a[i-1])
		{
			continue;
		}
		int lk = i;
		int k = a[i-1];
		printf("%d ", i);
		while (k != i)
		{
			printf("%d ", k);
			int temp = a[k - 1];
			a[k-1] = k;
			k = temp;
		}
		a[i-1] = i;
		printf("\n");
	}

	//fclose(stdin);
}