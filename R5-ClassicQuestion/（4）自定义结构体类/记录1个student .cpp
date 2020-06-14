#include<stdio.h>
main()
{
	struct student  //自定义名为student的结构体
	{
		int year,mouth,day;  //年月日定义为int 
		double number;  //学号定义为double 
		char name [100];  //名字定义为字符型的数组 
	}st1;  // 可以用st1来替换student，方便编写 
	while(scanf("%lf",&st1.number)!=EOF)
	{
		scanf(" %s %d.%d.%d",&st1.name,&st1.year,&st1.mouth,&st1.day);  //输入 
		getchar();  //等待下个输入，任意按键结束停留。用这个函数可以实现scanf到printf之间的停留。由于没有设置，所以从键盘上接受的内容不会赋值给任何变量 
		printf("%.0lf\n",st1.number);  //打印number，可以用 st1. 来调用需要输出的内容 
		puts(st1.name);  //利用puts函数输出字符串 
		printf("%04d.%02d.%02d\n",st1.year,st1.mouth,st1.day);  //分别设置不同精度的输出 
	}
}
