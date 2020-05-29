#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//小明的压岁钱

#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}

int main()
{
	int a, b, i, t, c,j;
	int bank[101];
	double sum = 0;
	IN2(a, b);
	sum = a;
	for (i = 0; i < b; i++) {
		IN2(t, c);
		sum += t;
		bank[i] = t;
		int m,n;
		for (j = 0; j < c; j++) {
			IN1(m);
			if (j == 0) {
				n = m;
				continue;
			}
			if (m > n) {
				n = m;
			}
		}
		sum *= 1.0 + ((double)n / 100);
	}
	for (i = 0; i < b; i++) {
		sum -= bank[i];
	}
	sum -= a;
	printf("%.2lf", sum);
}