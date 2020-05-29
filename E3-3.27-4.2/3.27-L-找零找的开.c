#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//卖口罩
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
long long a[200];

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int n, j, t = 0, i;
	int b1 = 0, b2 = 0, b5 = 0;
	char bbb;
	while (~scanf("%d", &n)) {
		b1 = 0; b2 = 0; b5 = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &t);
			switch (t)
			{
			case 1:
				b1++;
				break;
			case 2:
				if (b1 == 0) {
					OS("Bankrupted.\n");
					int count = 0;
					while (bbb = getchar() != '\n') {
						count++;
						if (count >= ((n << 1) + 1)) {
							return 0;
						}
						if (bbb == EOF) {
							return 0;
						}
					}
					goto loop;
				}
				b1--;
				b2++;
				break;
			case 5:
				if (b2 > 0) {
					b2--;
					if (b2 > 0) {
						b2--;
					}
					else {
						if (b1 < 2) {
							OS("Bankrupted.\n");
							int count = 0;
							while (bbb = getchar() != '\n') {
								count++;
								if (count >= ((n << 1) + 1)) {
									return 0;
								}
								if (bbb == EOF) {
									return 0;
								}
							}
							goto loop;
						}
						else {
							b1 -= 2;
						}
					}
				}
				else {
					if (b1 < 4) {
						OS("Bankrupted.\n");
						int count = 0;
						while (bbb = getchar() != '\n') {
							count++;
							if (count >= (n << 1) + 1) {
								return 0;
							}
							if (bbb == EOF) {
								return 0;
							}
						}
						goto loop;
					}
					else {
						b1 -= 4;
					}
				}
				break;
			default:
				break;
			}
		}
		OS("Survived.\n");
	loop:;
	}
	//fclose(stdin);
}