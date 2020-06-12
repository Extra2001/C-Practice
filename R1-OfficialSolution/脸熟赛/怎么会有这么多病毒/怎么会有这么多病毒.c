#include <stdio.h>

struct point{
	int a, b, c, k;
}virus[100005];

int s[300005];

int main() {
	int n, m;
	for (int i = 1; i <= 300003; i++) s[i] = -1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &virus[i].a, &virus[i].b, &virus[i].c);
		virus[i].k = virus[i].a + virus[i].b + virus[i].c;
		s[virus[i].k] = i;
	}
	int tot = 0;
	for (int i = 300003; i >= 1; i--) if (s[i] != -1) {
		tot++;
		if (tot > m || tot > n) break;
		printf("%d %d %d\n", virus[s[i]].a, virus[s[i]].b, virus[s[i]].c);
	}
	return 0;
}
