#include<stdio.h> 
#include<math.h>

int main(){

//定义数据 
int a[105];//存储成绩 
int sum=0,x,i=0,suml=0,sumh=0,nl=0,nh=0;
double avg,avgl,avgh;

//循环读入数据 
while(scanf("%d",&x)!=EOF){
	sum+=x;//求和 
	a[i+1]=x;//放入数组 
	i++;//计数 
}
avg=(double)sum/i;

//第二次遍历数组 
for(int j=1;j<=i;j++){
	if(a[j]>=avg){
		sumh+=a[j];
		nh++;
	}else if(a[j]<avg){
		suml+=a[j];
		nl++;
	}
}
avgl=(double)suml/nl;
avgh=(double)sumh/nh;

//判断是否为整数 
if((int)avg==avg){
	printf("%d %d\n",i,(int)avg);
}else{
	printf("%d %.2f\n",i,avg);
}
if((int)avgh==avgh){
	printf("%d %d\n",nh,(int)avgh);
}else{
	printf("%d %.2f\n",nh,avgh);
}
if((int)avgl==avgl){
	printf("%d %d\n",nl,(int)avgl);
}else{
	printf("%d %.2f\n",nl,avgl);
}

	
	return 0;
}
