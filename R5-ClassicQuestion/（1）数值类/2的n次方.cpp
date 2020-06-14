//题目：2的n次方
#include <math.h>  //导入数学库，因为要用到pow函数
#include <stdio.h> //导入基本库
int main()		   //主函数
{
	int n;									  //声明n
	double sum;								  //声明2的n次方
	printf("请输入n的值：");				  //输出一句话
	scanf("%d", &n);						  //从键盘获得n的值
	sum = pow(2, n);						  //求2的n次方的值，并赋给sun变量
	printf("2的%d次方的值为：%.0lf", n, sum); //输出n，和sum的值
	return 0;								  //返回值为零
}
