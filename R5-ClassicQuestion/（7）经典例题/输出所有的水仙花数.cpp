#include<stdio.h>
#include<math.h>
int main()
{
 int i,x,y,z,flag=0;
printf("输出所有的水仙花数：");
 for(i=100;i<=999;i++){
  x=i%10;
  y=(i/10)%10;
  z=i/100;        
 if(pow(x,3)+pow(y,3)+pow(z,3)==i && i!=1000)
{
flag=1;
  printf("%d ",i);
}
 }
if(flag==0)
printf("No\n");
 return 0;
}
