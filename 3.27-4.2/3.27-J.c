#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//1992 年 9 月 29 日
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
int cntDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int judge(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int contain92(int num) {
	int flag9 = 0, flag2 = 0;
	while (num) {
		int temp = num % 10;
		if (num < 10) {
			temp = num;
		}
		if (temp == 9) {
			flag9 = 1;
		}
		else if (temp == 2) {
			flag2 = 1;
		}
		num /= 10;
	}
	if (flag2 && flag9) {
		return 3;
	}
	else if (flag2) {
		return 1;
	}
	else if (flag9) {
		return 2;
	}
	else {
		return 0;
	}
}

int main()
{
	int n, j, t = 0, y, m, d, sum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		scanf("%d%d%d", &y, &m, &d);
		int ny = 1, nm = 1, nd = 1;
		for (ny = 1; ny <= y; ny++) {
			if (judge(ny)) {
				cntDay[1] = 29;
			}
			else {
				cntDay[1] = 28;
			}
			for (nm = 1; nm <= 12; nm++) {
				for (nd = 1; nd <= cntDay[nm - 1]; nd++) {
					if (nm == m && nd == d && ny == y) {
						int nny = ny * 10000, nnm = nm * 100;
						if (contain92(nny + nnm + nd) == 3) {
							sum++;
						}
						goto out;
					}
					int nny = ny * 10000, nnm = nm * 100;
					if (contain92(nny + nnm + nd) == 3) {
						sum++;
					}
				}
			}
		}
	out:
		printf("%d\n", sum);
	}


}