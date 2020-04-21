#include<stdio.h>
#include<math.h>
//TaoFu算进制转换
int b[2000];
void main()
{
	int a, k, m, i = 0;
	scanf("%d%d", &a, &k);
	if (a == 0) {
		printf("0");
		return;
	}
	while (a)
	{
		b[i] = a % k;
		i++;
		a = a / k;
	}
	for (i = i - 1; i >= 0; i--) {
		if (abs(b[i]) == 10) {
			printf("a");
		}
		else if (abs(b[i]) == 11) {
			printf("b");
		}
		else if (abs(b[i]) == 12) {
			printf("c");
		}
		else if (abs(b[i]) == 13) {
			printf("d");
		}
		else if (abs(b[i]) == 14) {
			printf("e");
		}
		else if (abs(b[i]) == 15) {
			printf("f");
		}
		else {
			printf("%d", abs(b[i]));
		}
	}
	printf("\n");
}