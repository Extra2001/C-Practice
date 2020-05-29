#include <stdio.h>
#include <math.h>
//听说出成绩了
int main() {
	int n, a, b, i;
	scanf("%d", &n);
	double c, d, sum=0.0;
	for(i=0; i<n; i++){
		scanf("%d%d", &a, &b);
		c = a;
		d= b;
		c *= 0.2;
		d *= 0.8;
		sum +=c;
		sum +=d;
	}
	printf("%.4lf", sum/n);
	return 0;
}