#include <stdio.h>
#include <math.h>
#include <string.h>
//W位数
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}
int s[2000];
int main() {
	long long int a = 0, b = 0, c, sum, i = 0, j, count = 0;
	//int s[200], o[200], o2[200];
	while (scanf("%lld%lld%lld", &a, &b, &c) != EOF) {
		sum = a + b;
		j = (long long int)1 << (c - 1);
			sum %= j << 1;
		if (sum > j - 1) {
			sum -= j << 1;
		}
		if (sum < -j) {
			sum += j << 1;
		}
		printf("%lld + %lld = %lld\n", a, b, sum);
	}
}