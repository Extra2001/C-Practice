#include<stdio.h>

int main(){
	// scanf("%s")   ֻ������һ������ 
	// getchar()     һ��ֻ�ܶ�һ���ַ�����   ͳ�ƿո����� 
	// gets/fgets    һ�ζ�һ��     �������飬�������ٸ��ո�
	 char c;
	 int ans=0;  // ��Ҫ���˳�ʼ�� 
	 char  str[2000];
//	 while((c=getchar())>30){   //��С��һ��ʵ���ַ���ASCII���Ǵ���30��\n\r����ĩ�ַ�����С��30�� 
//	 	if(c==' '){
//	 		ans++;
//		 }
//	 }
//printf("%d",ans+1);
	while(scanf("%s",str)>0){
		ans++;
	} 
	 printf("%d",ans);
	 return 0; 
}  
