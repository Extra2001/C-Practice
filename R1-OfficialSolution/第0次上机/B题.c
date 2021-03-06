/* 
 Author: 孟亚鹏
 Result: AC	Submission
 Attention：
 1.基本的注意事项，已在A题讲解
 2.下面讲解这类字符题的换行方法 
 本示例程序输出了两遍相同的符号 
 我们可以使用单个"\"符号在行末尾，为printf函数的参数字符串换行，这个"\"不会被输出
 值得注意的是，下一行从头开始，包括所有空格在内的字符都会被输出，所以，从第二行开始的开头，大家注意不要多出来空格 
 
 在vscode等编译器中可以使用多行光标快捷键，在多个位置同时插入相同字符（比如printf)大家可以自行查询，Dev c++并不支持 此功能 
 
*/

#include<stdio.h>

int main(){
	
	printf("         o                                             \n");
	printf("        <|>                                            \n");
	printf("        / \\                                            \n");
	printf("      o/   \\o       \\o__ __o     o__ __o/    o__  __o  \n");
	printf("     <|__ __|>       |     |>   /v     |    /v      |> \n");
	printf("     /       \\      / \\   / \\  />     / \\  />      //  \n");
	printf("   o/         \\o    \\o/   \\o/  \\      \\o/  \\o    o/    \n");
	printf("  /v           v\\    |     |    o      |    v\\  /v __o \n");
	printf(" />             <\\  / \\   / \\   <\\__  < >    <\\/> __/> \n");
	printf("                                       |               \n");
	printf("                               o__     o               \n");
	printf("                               <\\__ __/>               \n");
	
	printf("         o                                             \n\
        <|>                                            \n\
        / \\                                            \n\
      o/   \\o       \\o__ __o     o__ __o/    o__  __o  \n\
     <|__ __|>       |     |>   /v     |    /v      |> \n\
     /       \\      / \\   / \\  />     / \\  />      //  \n\
   o/         \\o    \\o/   \\o/  \\      \\o/  \\o    o/    \n\
  /v           v\\    |     |    o      |    v\\  /v __o \n\
 />             <\\  / \\   / \\   <\\__  < >    <\\/> __/> \n\
                                       |               \n\
                               o__     o               \n\
                               <\\__ __/>               ");

	return 0;
}
