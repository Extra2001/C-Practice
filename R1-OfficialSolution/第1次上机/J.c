/* 
 Author: ÕÅð©ÄÏ
 Result: AC	Submission_id: 2280507
 Created at: Fri Mar 13 2020 20:11:36 GMT+0800 (CST)
 Problem_id: 3042	Time: 732	Memory: 1624
*/

#include <stdio.h>
#include <math.h>
int a,b;
int flag;
int ans1;
int ans2;
int i;
int main(){
	while(scanf("%d%d",&a,&b)==2){
		ans1=0;
		ans2=0;
		if(a==b){
			puts("N");
		}
		else {
				for(i=1;i<a;i++){
			           if(a%i==0) ans1+=i;
	        	}
		        for(i=1;i<b;i++){
			            if(b%i==0) ans2+=i;
	         	}	
                if(ans1==b&&ans2==a){
                	puts("Y");
				}
				else puts("N"); 
		}
	
	}
    return 0; 
}
