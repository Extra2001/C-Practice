/* 
 Author: ÕÅð©ÄÏ
 Result: AC	Submission_id: 2280895
 Created at: Fri Mar 13 2020 20:17:08 GMT+0800 (CST)
 Problem_id: 3067	Time: 80	Memory: 1692
*/

#include <stdio.h>
#include <math.h>
int i;
int n,a;
int ans=0;
int main(){
   scanf("%d%d",&a,&n);
   a++;
   if(a==5) ans++;
   for(i=1;i<=n;i++){
   	   a++;
   	   if(a==5) ans++;
   	   else if(a==8) a=1;
   }
   printf("%d",ans);
    return 0; 
}
