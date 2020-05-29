#include <stdio.h>

int main()
{
	int b;
	scanf("%d", &b);
	if(b==0){
		printf("false");
		return 0;
	}
	if(b == 1){
		printf("true 0");
		return 0;
	}
	int i = 1;
	if((b&(b-1)) == 0){
		while(b != 2){
			b >>= 1; 
			i++;
		}
		printf("true %d", i);
	}
	else{
		printf("false");
	}
	return 0;
}