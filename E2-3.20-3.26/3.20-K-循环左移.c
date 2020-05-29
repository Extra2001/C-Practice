#include <stdio.h>
#include <math.h>
#include <string.h>
//我家大小姐不想让我告白
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}
char s[2000];
char temp[2000];
int set(int wei, int toop, char toset) {
	int set = 0;
	if (toset == '1') {
		set = 1;
	}
	int i = 1;
	i <<= wei;
	if (set == 1){
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
int main() {
	int m, N, n, a, i, j, k, ans = 0;
	scanf("%d%d", &m, &N);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &n, &a);
		j = 0;
		while (a >> j > 0) {
			j++;
		}
		for (k = 0; k < N; k++) {
			if (k >= j) {
				s[k] = '0';
				continue;
			}
			int a0 = a & (1 << k);
			if (a0 > 0) {
				s[k] = '1';
			}
			else {
				s[k] = '0';
			}
		}
		for (k = 0; k < n; k++) {
			zuoyi(N);
		}
		for (k = 0; k < N; k++) {
			ans = set(k, ans, s[k]);
		}
		printf("%d\n", ans);
	}
}