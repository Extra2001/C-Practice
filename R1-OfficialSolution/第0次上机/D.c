#include <stdio.h>
#include <math.h>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(!b)printf("ERROR. The divisor is ZERO.");
	else {
		printf("%d div %d = %d ... %d",a,b,a/b,a%b);
	}
	return 0;
}
