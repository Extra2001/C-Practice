#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//质量弹簧阻尼
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}
#define OS(c) printf("%s", c);
#define OD(d) printf("%.2lf", d);
long long a[200];


int main()
{
	//记得注释！

	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int n, j, i;
	double m, b, k, x0, t0, v = 0, x, t, x_1, v_1 = 0;
	scanf("%lf%lf%lf", &m, &b, &k);
	scanf("%lf%lf", &x0, &t0);
	n = t0 / 10e-8;	x = x_1 = x0;
	for (i = 0; i < n-1; i++) {
		x_1 = x;
		v_1 = v;
		x = x_1 + 10e-8 * v_1;
		v = v_1 - (10e-8 / m) * (b * v_1 + k * x_1);
	}
	printf("%.8lf", x);


	//fclose(stdin);
}