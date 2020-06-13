#include <stdio.h>
#include <math.h>
//aikx解方程
int main() {
	int aa, bb, cc;
	double a, b, c, delta, x1, x2, temp;
	while (scanf("%d%d%d", &aa, &bb, &cc) != EOF) {
		if (aa == 0 && bb == 0) {
			printf("NO Solution\n");
			continue;
		}
		a = aa;
		b = bb;
		c = cc;
		delta = b * b - 4*a*c;
		if (delta < 0) {
			printf("NO Solution\n");
		}
		else if (delta == 0) {
			x1 = (-b) / (2 * c);
			if (x1 == 0) {
				printf("NO Solution\n");
			}
			else {
				printf("%.2lf\n", x1);
			}
		}
		else {
			x1 = ((-b) + sqrt(delta)) / (2 * c);
			x2 = ((-b) - sqrt(delta)) / (2 * c);
			if (x1 > x2) {
				temp = x1;
				x1 = x2;
				x2 = temp;
			}
			if (x1 == 0) {
				printf("%.2lf\n", x2);
			}
			else if (x2 == 0) {
				printf("%.2lf\n", x1);
			}
			else {
				printf("%.2lf %.2lf\n", x1, x2);
			}
		}
	}
	return 0;
}