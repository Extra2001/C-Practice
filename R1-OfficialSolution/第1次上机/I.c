#include<stdio.h> 
#include<math.h>

int main(){

//�������� 
int a[105];//�洢�ɼ� 
int sum=0,x,i=0,suml=0,sumh=0,nl=0,nh=0;
double avg,avgl,avgh;

//ѭ���������� 
while(scanf("%d",&x)!=EOF){
	sum+=x;//��� 
	a[i+1]=x;//�������� 
	i++;//���� 
}
avg=(double)sum/i;

//�ڶ��α������� 
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

//�ж��Ƿ�Ϊ���� 
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
