#include<stdio.h>

int main(){
	// scanf("%s")   只能输入一个单词 
	// getchar()     一次只能读一个字符进来   统计空格数量 
	// gets/fgets    一次读一行     遍历数组，对数多少个空格
	 char c;
	 int ans=0;  // 不要忘了初始化 
	 char  str[2000];
//	 while((c=getchar())>30){   //最小的一个实体字符的ASCII码是大于30，\n\r等行末字符都是小于30的 
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
