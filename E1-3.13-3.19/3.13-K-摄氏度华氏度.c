#include <stdio.h>
#include <math.h>
#include <string.h>
//温度转换 II
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}

int main() {
	int op, L, R, i;
	IN3(op, L, R);
	if(op==1){
		for(i = 0; i< R-L+1; i++){
			printf("%d %.1lf\n", L+i, (double)(L+i)*9.0/5.0+32.0);
		}
	}
	else{
		for(i = 0; i< R-L+1; i++){
			printf("%d %.1lf\n", L+i, (double)(L+i-32)*5.0/9.0);
		}
	}
}