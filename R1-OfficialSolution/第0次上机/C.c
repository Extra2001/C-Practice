#include <stdio.h>
#include <math.h>
int n;
int main(){
	scanf("%d",&n);
	if(n<0){
		printf("-1");
	}
	else if(n==0){
		printf("0");
	}
	else {
		printf("1");
	}
	return 0;
}
