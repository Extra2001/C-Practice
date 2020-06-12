#include<stdio.h>
#include<math.h>

double convert(int x);

double convert(int x){
	return (300.0*x)/55.0;
	//这是个函数，不理解的话可以把所有的convert直接带入这个计算式 
	//解方程 a时b分时针分针重合的角度条件：30*a+0.5*b=6*b 
}

int main(){
	int a,b;
	double q;
	int q_int;	
	scanf("%d:%d",&a,&b);
	//输入数据测试时，请注意输入英文冒号，不要输入中文状态下冒号 
	q=convert(a);
	q_int=round(q);
	
	if(q_int==b){
		printf("Bingo!");
	}
	else if(q_int==60){
		printf("The next time is 0:00");
		//对解出11:60做特殊处理 
	}
	else if(q_int>b){
		printf("The next time is %d:%02d",a,q_int);	
		//使用格式控制修饰符 解决加不加前置0的问题 
	}else if(q_int<b){
		q_int=(int)round(convert(a+1));
		printf("The next time is %d:%02d",a+1,q_int);
	}
	
	return 0;
} 
