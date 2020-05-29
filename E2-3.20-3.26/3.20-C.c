#include <stdio.h>
#include <math.h>
#include <string.h>
//求阶乘
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}

int main() {
	long long int a = 0, b = 1, i, j, count = 0;
	//int s[200], o[200], o2[200];
	scanf("%lld", &a);
	if (a == 0) {
		OUT1(1);
		return;
	}
	while (a != 1) {
		b *= a;
		a--;
	}
	printf("%d\n", b % 1000033);
}