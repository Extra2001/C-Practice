#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
int main(){
	
	int a,j =0, i=0, sum=0;
	while(1==1){
		scanf("%d", &a);
		if(a==-1){
			break;
		}
		sum+=a;
		if(a<60){
			i++;
		}
		j++;
	}
	printf("Average:%d\nFailed:%d", sum/j, i);
}