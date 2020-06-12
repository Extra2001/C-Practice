#include<stdio.h>

// 最小公倍数=a*b/gcd(a,b) 

int gcd(int a,int b){
	int i;
	for(i=b;i>=1;--i){
		if(a%i==0 && b%i==0){
			break;
		}
	}
	return i;
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",a*b/gcd(a,b));
} 
