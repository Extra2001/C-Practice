#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//小胖吃自助
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
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int n, i, st = 1, count = 0, stm = 1, en = 0;
	long long a[101] = { 0 }, sum = 0, summ = 0;
	while (~scanf("%d", &n)) {
		st = stm = 1;
		count = en = summ = sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
			if (a[i] < 0) {
				count++;
			}
			sum += a[i];
			if (sum < 0) {
				sum = 0;
				stm = i + 2;
			}
			else if (summ == sum && i + 1 - stm > en - st) {
				en = i + 1;
				st = stm;
			}
			else if (sum > summ) {
				summ = sum;
				en = i + 1;
				st = stm;
			}
		}
		if (count >= n) {
			printf("I'm hungry!\n");
		}
		else {
			printf("%lld %d %d\n", summ, st, en);
		}
	}
	//fclose(stdin);
}