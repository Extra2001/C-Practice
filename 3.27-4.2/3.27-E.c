#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//人肉指南针
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
	int a, b;
	IN2(a, b);
	if (a == 0 && b == 0) {
		printf("Bingo");
		return 0;
	}
	else if (a == 0 && b > 0) {
		OS("N");
		return 0;
	}
	else if (a == 0 && b < 0) {
		OS("S");
		return 0;
	}
	else if (b == 0 && a > 0) {
		OS("E");
		return 0;
	}
	else if (b == 0 && a < 0) {
		OS("W");
		return 0;
	}
	double t = atan((double)b / (double)a) * 180 / PI;
	t = fabs(t);
	if (a > 0 && b > 0) {
		OS("NE");
		OD(90 - fabs(t));
	}
	else if (a > 0 && b < 0) {
		OS("SE");
		OD(90 - fabs(t));
	}
	else if (a < 0 && b > 0) {
		OS("NW");
		OD(90 - fabs(t));
	}
	else if (a < 0 && b < 0) {
		OS("SW");
		OD(90 - fabs(t));
	}
}