#include <stdio.h>

int n, a[15], vis[15];

void dfs(int pos) {
	if (pos > n) {
		for (int i = 1; i <= n; i++) 
			printf("%d ", a[i]);
		printf("\n");
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		a[pos] = i; vis[i] = 1;
		dfs(pos + 1);
		vis[i] = 0;
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}