#include <stdio.h>
#include <math.h>
#include <string.h>
//You underestimate my power!
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}

int main() {
	int a[6], b[6], i, sum= 0;
	FIN(6,a);
	FIN(6,b);
	for(i = 0 ;  i<6; i++){
		if(b[i]<a[i]){
			sum++;
		}
	}
	OUT1(sum);
}