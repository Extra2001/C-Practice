#include <stdio.h>
#include <math.h>
#include <string.h>
//宋老师的进制转化2
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
	long long int a = 0, b = 1, i = 0, j, count = 0;
	//int s[200], o[200], o2[200];
	while (scanf("%lld", &a) != EOF) {
		i = 0;
		if (a == 0) {
			printf("0\n");
			continue;
		}
		while (a >= 1) {
			s[i] = a % 3;
			a /= 3;
			i++;
		}
		if (i >= 5) {
			printf("LONG");
		}
		for (j = i - 1; j >= 0; j--) {
			printf("%d", s[j]);
		}
		printf("\n");
	}
}