#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//签到之GPA计算
int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int i, n, j = 0, flag = 1;
	double xuefensum = 0;
	double score[15], xuefen[15], gp[15], gpa=0.0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf", &score[i], &xuefen[i]);
		xuefensum += xuefen[i];
		if (score[i] < 60) {
			gp[i] = 0.0;
		}
		else {
			gp[i] = 4.0 - 3.0 * ((100.0 - score[i])* (100.0 - score[i]) / 1600.0);
		}
	}
	for (i = 0; i < n; i++) {
		gpa += gp[i] * xuefen[i] / xuefensum;
	}
	printf("%.4lf", gpa);
	//fclose(stdin);
}