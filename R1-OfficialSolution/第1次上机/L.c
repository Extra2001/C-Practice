#include<stdio.h>
#include<math.h>

double convert(int x);

double convert(int x){
	return (300.0*x)/55.0;
	//���Ǹ������������Ļ����԰����е�convertֱ�Ӵ����������ʽ 
	//�ⷽ�� aʱb��ʱ������غϵĽǶ�������30*a+0.5*b=6*b 
}

int main(){
	int a,b;
	double q;
	int q_int;	
	scanf("%d:%d",&a,&b);
	//�������ݲ���ʱ����ע������Ӣ��ð�ţ���Ҫ��������״̬��ð�� 
	q=convert(a);
	q_int=round(q);
	
	if(q_int==b){
		printf("Bingo!");
	}
	else if(q_int==60){
		printf("The next time is 0:00");
		//�Խ��11:60�����⴦�� 
	}
	else if(q_int>b){
		printf("The next time is %d:%02d",a,q_int);	
		//ʹ�ø�ʽ�������η� ����Ӳ���ǰ��0������ 
	}else if(q_int<b){
		q_int=(int)round(convert(a+1));
		printf("The next time is %d:%02d",a+1,q_int);
	}
	
	return 0;
} 
