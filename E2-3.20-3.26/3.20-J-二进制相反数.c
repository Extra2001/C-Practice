#include <stdio.h>
#include <math.h>
#include <string.h>
//求相反数
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}
char s[200000];
char temp[200000];
int set(int wei, int toop, char toset) {
	int set = 0;
	if (toset == '1') {
		set = 1;
	}
	int i = 1;
	i <<= wei;
	if (set == 1) {
		return (toop | i);
	}
	else {
		return (toop & (~i));
	}
}
void zuoyi(int N) {
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			temp[0] = s[i];
			break;
		}
		temp[i + 1] = s[i];
	}
	for (int i = 0; i < N; i++) {
		s[i] = temp[i];
	}
}
void qufan(int n) {
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			s[i] = '0';
		}
		else {
			s[i] = '1';
		}
	}
}
int main() {
	int flag = 1;
	while (scanf("%s", s) != EOF) {
		int n = strlen(s);
		if (s[0] == '1') { //负数，减一取反
			for (int i = 0; i < n; i++) {
				if (i == n - 1) {
					printf("0verf1ow!\n");
					flag = 0;
					break;
				}
				if (s[n - i - 1] == '1') {
					s[n - i - 1] = '0';
					flag = 1;
					break;
				}
				else {
					s[n - i - 1] = '1';
				}
			}
			qufan(n);
		}
		else {
			for (int i = 0; i < n; i++) {
				if (s[i] != '0') {
					break;
				}
				if (i == n - 1) {
					goto out;
				}
			}
			qufan(n);
			for (int i = 0; i < n; i++) {
				if (i == n - 1) {
					printf("0verf1ow!\n");
					flag = 0;
					break;
				}
				if (s[n - i - 1] == '0') {
					s[n - i - 1] = '1';
					flag = 1;
					break;
				}
				else {
					s[n - i - 1] = '0';
				}
			}
		}
		out:
		if (flag) {
			for (int i = 0; i < n; i++) {
				printf("%c", s[i]);
			}
			printf("\n");
		}
	}
}