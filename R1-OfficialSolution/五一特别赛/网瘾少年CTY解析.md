# 网瘾少年CTY解析
|考点|难度|
|---|---|
|二维数组|3|
## 题目分析
用二维数组存储所有的点，对于每个是雷的点，将其周围所有不是雷的点数值+1即可。
要注意一下几点：

1. 读入的时候每行末尾会有多余的\r和\n
2. 小心数组越界
## 示例代码
~~~c
#include <stdio.h>

char a[10][10];
void fun1(int i,int j)
{
	if(i>=0&&i<10&&j>=0&&j<10){
		if(a[i][j]!='X')
			a[i][j]+=1;
	}
	return;
}//将第i行第j列数值+1，同时保证不是雷且不越界
void fun2(int i,int j)
{
	fun1(i-1,j-1);
	fun1(i-1,j);
	fun1(i-1,j+1);
	fun1(i,j-1);
	fun1(i,j+1);
	fun1(i+1,j-1);
	fun1(i+1,j);
	fun1(i+1,j+1);
}//将第i行第j列周围所有格数值+1
int main(void)
{
	int i,j;
	for(i=0;i<10;i++){//读入
		for(j=0;j<10;j++)
			scanf("%c",&a[i][j]);
		while(getchar()!='\n');//吃掉末尾的换行符
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(a[i][j]=='X')
				fun2(i,j);
		}
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			switch(a[i][j]){
				case 'X':printf("X");break;//雷按原样输出
				case '0':printf(" ");break;//‘0’则输出空格
				default:printf("%c",a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}

~~~