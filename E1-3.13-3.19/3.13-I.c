#include <stdio.h>
#include <math.h>
#include <string.h>
//成绩统计2
int main() {
	int a, b=0 ,c=0 ,d = 0,i=0, g=0 , h=0 ,k;
	int n=0, e[200], f[200];
	while(scanf("%d",&a)!=EOF){
		b+=a;
		e[n]=a;
		n++;
	}
	double ava = (double)b / n;
	for(; i<n;i++){
		if(e[i]>=ava){
			c+=e[i];
			g++;
		}
		else{
			d+=e[i];
			h++;
		}
	}
	double ava1 = (double)c/g;
	double ava2 = (double)d/h;
	k = ava;
	if((double)k==ava){
		printf("%d %d\n", n, k );
	}
	else{
		printf("%d %.2lf\n",n ,ava);
	
	}
	k = ava1;
	if((double)k==ava1){
		printf("%d %d\n", g, k );
	}
	else{
		printf("%d %.2lf\n",g ,ava1);
	
	}
	k = ava2;
	if((double)k==ava2){
		printf("%d %d\n", h, k );
	}
	else{
		printf("%d %.2lf\n", h ,ava2);
	
	}
	
	
}