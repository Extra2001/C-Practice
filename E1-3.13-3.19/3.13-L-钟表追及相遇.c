#include <stdio.h>
#include <math.h>
#include <string.h>
//小明的钟表问题
int main() {
//	int a[24];
	int hh, mm,i;
	
	scanf("%d:%d", &hh, &mm);
	int a[13] = {0,5,11,16,22,27,33,38,44,49,55,-1,0};
	for(i = 0; i< 12; i++){
		if(a[hh]==mm){
			printf("Bingo!");
			return 0;
		}
	}
	if(hh == 11){
		printf("The next time is %d:%02d", 0, 00);
		return 0;
	}
	if(a[hh] < mm){
		hh++;
	}
	if(hh==11){
		hh=0;
	}
	printf("The next time is %d:%02d", hh, a[hh]);
}