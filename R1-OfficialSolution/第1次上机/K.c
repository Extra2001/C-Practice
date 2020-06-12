#include <stdio.h>
#include <math.h>
int op,l,r;
int i;
double ans;
int main(){
	scanf("%d%d%d",&op,&l,&r); 	
	if(op==2){
		for(i=l;i<=r;i++){
			printf("%d %.1lf\n",i,(double)(i-32)*5/9);
		}
	} 
	else if(op==1){
		for(i=l;i<=r;i++){
	         printf("%d %.1lf\n",i,(double)(i)*9/5+32);
	    }	
	} 

	return 0;
}
//1233,8833,
