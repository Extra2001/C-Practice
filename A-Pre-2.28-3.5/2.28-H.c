#include <stdio.h>

int main()
{
	int a[10] = {0,6,66,666,6666,66666,666666,6666666,66666666,666666666};
	int b,c = 0;
	scanf("%d", &b);
	for (int i = 0; i < b + 1; i++){
		c += a[i];
	}
	printf("%d", c);
}