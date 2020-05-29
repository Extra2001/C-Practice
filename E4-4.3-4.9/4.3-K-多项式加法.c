#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//水水の多项式加法
long long xi[20005] = { 0 }, ci[10005] = { 0 };

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	long long xishu, cishu;
	char unknowun;
	while (~scanf("%lld%c%lld", &xishu, &unknowun, &cishu))
	{
		ci[cishu]++;
		xi[cishu] += xishu;
	}
	for (int i = 0; i < 10005; i++) {
		if (xi[i] != 0) {
			printf("%+lld%c%d", xi[i], unknowun, i);
		}
	}
	//fclose(stdin);
}