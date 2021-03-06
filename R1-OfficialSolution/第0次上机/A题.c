/* 
 Author: 孟亚鹏
 Result: AC	Submission
 Attention：
 1.首先是基本的注意事项，比如说语句末尾不要忘记分号，使用printf等输入输出函数时，要先添加头文件<stdio.h>，
 程序末尾要 return 0;表示无异常结束。Dev C++有时允许不加return 0，也能编译成功，但OJ系统不一定允许，这并不是一种很好的习惯
 2.对于本类题而言，推荐大家从题目页面直接复制字符，注意不要漏掉行末尾用来对齐的空格
 推荐大家使用查找替换功能完成转义字符 "\"与"\\"的替换 
 3.注意常见的转义字符 
 一类是由反斜杠\引出的，\n代表换行，还有\b,\t\a等功能大家可以查表
 值得注意的是 ，如果要输出"\"本身，需要输入"\\"
  另一类是格式限定符，类似%d，要输出%时，请使用%%
  4.大家一定要区分正斜杠"/"和反斜杠"\"，反斜杠才引领转义字符，正斜杠在字符串内正常使用即可（正斜杠在行末尾的注释用法大家也要掌握） 
  5.关于这类字符题换行的方法将在B题讲解 
  
*/

#include<stdio.h>

int main(){
	
	printf("﹎ ┈ ┈ .o┈ ﹎  ﹎.. ○\n");
	printf("﹎┈﹎●  ○ .﹎ ﹎o▂▃▅▆\n");
	printf("┈ ┈ /█\\/▓\\ ﹎ ┈ ﹎﹎ ┈ ﹎\n");
	printf("▅▆▇█████▇▆▅▃▂┈﹎");
	
	return 0;
}
