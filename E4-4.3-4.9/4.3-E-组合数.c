#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//小明又去春游
int ack(int, int);
int C(int m, int n);
int getFactorial(int);

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int m, x;
	scanf("%d%d", &m, &x);

	printf("%d", C(m, 8-x));
	//fclose(stdin);
}

//组合数
int C(int n, int m){
	return getFactorial(n) / (getFactorial(m) * getFactorial(n - m));
}
//阶乘
int getFactorial(int n)
{
    if (n <= 1)
        return 1;
    return n * getFactorial(n - 1);
}