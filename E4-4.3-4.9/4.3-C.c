#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//SIR 模型算感染人数
int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int s0, i0, r0, n, i;
	double b, y;
	scanf("%d%d%d%d%lf%lf", &s0, &i0, &r0, &n, &b, &y);
	int N = s0 + r0 + i0;
	double sn = s0, sn1, in = i0, in1, rn = r0, rn1;
	for (i = 0; i < n;i++){
		sn1 = sn - b * (sn * in / (double)N);
		in1 = in - y * in + b * (sn * in / (double)N);
		rn1 = rn + y * in;
		rn = rn1;
		in = in1;
		sn = sn1;
	}
	printf("%d", (int)(in + 0.5));

	//fclose(stdin);
}