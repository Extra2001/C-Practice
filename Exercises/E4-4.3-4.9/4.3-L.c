#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//原根

//欧拉函数 φ(n) 为小于或等于 n 的正整数中与 n 互质的数的个数。
int Phi(int x){
	int i;
	int ret = x;
	for(i = 2; i * i <= x; i++){
		if(x % i == 0){
			ret = ret / i * (i - 1);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) ret = ret / x * (x - 1);
	return ret;
}

//最大公约数
int GCD(int a, int b){
	return b ? GCD(b, a % b) : a;
}

//次方后取余，a的t次方与p取余
int PowMod(int a, int t, int p){
	int ret = 1;
	while(t){
		if(t & 1) ret = ret * a % p;
		a = a * a % p;
		t >>= 1;
	}
	return ret;
}

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int n, p;
	scanf("%d", &n);
	for (int i = 0; i < n;i++){
		int bigflag = 1;
		scanf("%d", &p);
		int d = Phi(p);
		for (int a = 1; a <= p;a++){
			if(GCD(a,p)==1){
				int admodp = PowMod(a, d, p);
				if(1%p==admodp){
					int flag = 1;
					for (int j = 1; j < d;j++){
						if(PowMod(a,j,p)==1%p){
							flag = 0;
						}
					}
					if(flag){
						printf("%d ", a);
						bigflag = 0;
					}
				}
			}
		}
		if(bigflag){
			printf("-1\n");

		}
		else {
			printf("\n");
		}
	}
	//fclose(stdin);
}