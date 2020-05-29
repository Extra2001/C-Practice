#include <stdio.h>

int main()
{
	int n,i,k,sum = 0;
	scanf("%d", &n);
	for(i = 1; i <= n ; i++){
		scanf("%d", &k);
		sum += (n+1-i)*k;
	}
	printf("%d\n",sum);

	return 0;
}