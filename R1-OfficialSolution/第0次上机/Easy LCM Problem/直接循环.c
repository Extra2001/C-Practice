#include<stdio.h>

// i,能够同时被a和b整除
//  a<=1000,b<=1000
// i<=1000000 
// 这个大小的数字是完全可以使用计算机通过遍历得到的。
// 遍历：尝试每一个可能的答案
 



int main(){
	int a,b,i;
	
	scanf("%d %d",&a,&b);  //两个%d间的空格可有可无 
	
	for(i=a;!(i%a==0 && i%b==0);++i);   //不能没有这个分号 
	//++i,i++,i=i+1,i+=1  在这里都是可以的 
	
	printf("%d",i);
}
