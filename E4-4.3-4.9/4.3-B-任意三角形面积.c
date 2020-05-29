#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//简单的三角形面积
int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	double x1, x2, x3, y1, y2, y3;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	double s1 = x2 * y3 - y2 * x3;
	double s2 = y1 * x3 - x1 * y3;
	double s3 = x1 * y2 - x2 * y1;

	printf("%.4lf", 0.5 * (s1 + s2 + s3));

	//fclose(stdin);
}