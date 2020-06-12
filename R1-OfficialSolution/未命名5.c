#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main()
{
	double x, y;
	scanf("%d%d",&x,&y);

	if(x==0 && y==0){
		printf("Bingo");
	}
	else if(x>0 && y==0){
		printf("E\n");
	}
	else if(x<0 && y==0){
		printf("W\n");
	}
	else if(x==0 && y>0){
		printf("N\n");
	}
	else if(x==0 && y<0){
		printf("S\n");
	}
	else if(x>0 && y>0){
		printf("NE%.2f\n",atan(x/y) * 180 / PI);
	}
	else if(x<0 && y>0){
		printf("NW%.2f\n",atan((-x)/y) * 180 / PI);
	}
	else if(x<0 && y<0){
		printf("SW%.2f\n",atan((-x)/(-y)) * 180 / PI);
	}
	else if(x>0 && y<0){
		printf("SE%.2f\n",atan(x/(-y)) * 180 / PI);
	}
	
	return 0;
} 
