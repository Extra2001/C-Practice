#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Random Star
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		n *= 2;
		n++;
		int i = 0;
		for (; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == (n - 1) / 2) {
					printf("*");
				}
				else {
					if (j == i || n - j - 1 == i) {
						printf("*");

					}
					else {
						printf(" ");
					}
				}
			}
			printf("\n");
		}
		printf("\n");
	}

}