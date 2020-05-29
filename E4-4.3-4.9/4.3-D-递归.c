#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//求阿克曼函数
int ack(int, int);

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", ack(a, b));
	//fclose(stdin);
}

int ack(int a, int b){
	if(a==0){
		return b + 1;
	}
	if(b==0){
		return ack(a - 1, 1);
	}
	return ack(a - 1, ack(a, b - 1));
}