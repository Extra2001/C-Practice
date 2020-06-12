#include<stdio.h>

int main(){
		int n,i,a=6,sum=0;    // 一定别忘了初始化 
	scanf("%d",&n); 
	// case后面的东西只能是int 
	switch(n){
		case 0:sum=0;break;
		case 1:sum=6;break;
		case 2:sum=72;break;
		case 3:sum=738;break;
		case 4:sum=7404;break;
		case 5:sum=74070;break;
		case 6:sum=740736;break;
		case 7:sum=7407402;break;
		case 8:sum=74074068;break;
		case 9:sum=740740734;break;
	}
	printf("%d",sum);
} 
