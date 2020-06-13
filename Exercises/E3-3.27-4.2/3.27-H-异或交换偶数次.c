#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//找零件, 唯一一个出现次数不是偶数次的那个数
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

int main()
{
	int n, d = 0, t, i;
	IN1(n);
	int xun = (n << 1) - 1;
	for (i = 0; i < xun; i++) {
		scanf("%d", &t);
		d ^= t;
	}
	OUT1(d);
}