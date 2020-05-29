#include <stdio.h>
#include <math.h>
#include <string.h>
//火仙草数
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}

int main() {
	int n, i ,a,flag=1;
	IN1(n);
	while(n<10000&&flag){
		a = n / 100;
		i = n % 100;
		if(i*i+a*a==n){
			flag = 0;
		}
		else{
			n++;
		}
	}
	if(flag==0){
		printf("%d",n);
	}
	else{
		printf("-1");
	}
}