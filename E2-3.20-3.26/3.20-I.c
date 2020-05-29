#include <stdio.h>
#include <math.h>
#include <string.h>
//A op B Problem
unsigned int set(int wei, unsigned int toop, int toset) {
	unsigned int i = 1;
	i <<= wei;
	if (toset == 1) {
		return (toop | i);
	}
	else {
		return (toop & (~i));
	}
}
int main() {
	unsigned int sum, i = 0, ans = 0, a, b, a0, b0;
	int w0, w1, w2, w3, q, m;
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%u%u", &a, &b);
		scanf("%d%d%d%d", &w0, &w1, &w2, &w3);
		if (a == 0 && b == 0) {
			printf("0\n");
			continue;
		}
		for (m = 0; m < 32; m++) {
			a0 = a & ((unsigned int)1 << m);
			b0 = b & ((unsigned int)1 << m);
			if (a0 > 0 && b0 > 0) {
				ans = set(m, ans, w3);
			}
			else if (a0 > 0 && b0 == 0) {
				ans = set(m, ans, w2);
			}
			else if (a0 == 0 && b0 > 0) {
				ans = set(m, ans, w1);
			}
			else {
				ans = set(m, ans, w0);
			}
		}
		printf("%u\n", ans);
	}
}