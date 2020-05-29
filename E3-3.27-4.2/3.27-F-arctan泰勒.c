#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//拔剑吧少年
#define PI 3.14159265

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

double arctanx(int n, double x) {
	int i = 0;
	double sum = 0;
	for (; i < n; i++) {
		int h1 = 1;
		double h2 = 1, h3 = 1.0 / (double)(2.0 * (double)(i + 1) - 1.0);
		for (int j = 0; j < i; j++) {
			h1 *= -1;
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			h2 *= x;
		}
		sum += h1 * h2 * h3;
	}
	return sum;
}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		n++;
		n /= 2;
		//n++;
		printf("%.9lf\n", (16.0 * arctanx(n, 1.0 / 5.0) - 4.0 * arctanx(n, 1.0 / 239.0)));
	}
}