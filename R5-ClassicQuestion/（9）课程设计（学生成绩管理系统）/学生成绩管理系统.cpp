#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int input(struct student *parr, int len);		//函数功能：输入数据
int output(struct student *parr, int len);		//函数功能：打印信息
int findnum(struct student *parr, int len);		//函数功能：按学号找学生信息
int findname(struct student *parr, int len);	//函数功能：按姓名找学生信息
int modify(struct student *parr, int len);		//函数功能：修改学生信息
int add(struct student *parr, int len);			//函数功能：增加学生信息
int del(struct student *parr, int len);			//函数功能：删除学生信息
int statistics1(struct student *parr, int len); //函数功能：按平均分统计各个分数段的学生人数
int statistics2(struct student *parr, int len); //函数功能：找出3门课程成绩最高的学生，并输出他们的信息
int statistics3(struct student *parr, int len); //函数功能：统计3门课程的不及格率
int write(struct student *parr, int len);		//函数功能：将数据写入文件
void exit(struct student *parr, int len);		//函数功能：结束整个程序
struct student
{
	int number;		   //学号
	char name[100];	   //姓名
	char collage[100]; //学院
	char banji[100];   //班级
	float score1;	   //高数成绩
	float score2;	   //英语成绩
	float score3;	   //C语言成绩
	float sum;		   //总分
	float ave;		   //平均分
};
int main()
{

	struct student *parr;
	int len = 0;
	char ch = '\0';
	system("color 0A");
	printf("\t\t|**************************************************|\n");
	printf("\t\t|-------------欢迎使用学生成绩管理系统-------------|\n");
	printf("\t\t|**************************************************|\n");

	printf("\n\n\t\t请输入需要存入的学生人数：");
	scanf("%d", &len);
	parr = (struct student *)malloc((sizeof(struct student) * 1000));
	printf("按回车键继续\n");
	while (1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t|**************************************************|\n");
		printf("\t\t|--------学生管理系统 ----------------------------|\n");
		printf("\t\t|------- a.写入学生信息----------------------------|\n");
		printf("\t\t|------- b.查看全部学生信息------------------------|\n");
		printf("\t\t|------- c.按学号查找------------------------------|\n");
		printf("\t\t|------- d.按姓名查找------------------------------|\n");
		printf("\t\t|------- e.修改学生信息----------------------------|\n");
		printf("\t\t|------- f.增加学生信息----------------------------|\n");
		printf("\t\t|------- g.删除学生信息----------------------------|\n");
		printf("\t\t|------- h.按平均分统计各个分数段的学生人数--------|\n");
		printf("\t\t|------- i.找出3门课程成绩最高的学生，并输出信息---|\n");
		printf("\t\t|------- j.统计3门课程的不及格率-------------------|\n");
		printf("\t\t|------- k.保存-----------------------------------|\n");
		printf("\t\t|------- 0.退出------------------------------------|\n");
		printf("\t\t|**************************************************|\n");
		printf("\t\t\n");
		scanf(" %c", &ch);
		switch (ch)
		{
		case 'a':
			len = input(parr, len);
			break;
		case 'b':
			len = output(parr, len);
			break;
		case 'c':
			len = findnum(parr, len);
			break;
		case 'd':
			len = findname(parr, len);
			break;
		case 'e':
			len = modify(parr, len);
			break;
		case 'f':
			len = add(parr, len);
			break;
		case 'g':
			len = del(parr, len);
			break;
		case 'h':
			len = statistics1(parr, len);
			break;
		case 'i':
			len = statistics2(parr, len);
			break;
		case 'j':
			len = statistics3(parr, len);
			break;
		case 'k':
			len = write(parr, len);
			break;
		case '0':
			exit(parr, len);
			break;
		default:
			printf("\n\t输入错误!按回车键返回主菜单！");
			getch();
		}
	}
	free(parr);
	return 0;
}
//函数功能：打印信息
int output(struct student *parr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (parr[i].number != 0)
			printf("姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f \nC语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
	}
	printf("\n");
	getchar();
	getchar();
	return len;
}
//函数功能：输入数据
int input(struct student *parr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("请输入学生信息：");
		printf("姓名：");
		scanf("%s", parr[i].name);
		printf("学号：");
		scanf("%d", &parr[i].number);
		printf("学院：");
		scanf("%s", parr[i].collage);
		printf("班级：");
		scanf("%s", parr[i].banji);
		printf("高数成绩:");
		scanf("%f", &parr[i].score1);
		printf("英语成绩：");
		scanf("%f", &parr[i].score2);
		printf("C语言成绩：");
		scanf("%f", &parr[i].score3);
		parr[i].sum = parr[i].score1 + parr[i].score2 + parr[i].score3;
		parr[i].ave = parr[i].sum / 3.0;
	}
	printf("\n");
	return len;
}
//函数功能：将数据写入文件
int write(struct student *parr, int len)
{
	int i;								 //控制循环
	FILE *fp = NULL;					 //定义文件指针
	fp = fopen("D:\\student.bin", "wb"); //打开文件并使文件指针指向它，以写的方式
	if (fp == NULL)						 //如果文件没有打开，提示错误并退出
	{
		printf("\n\t文件没有打开！程序结束！");
		getchar(); //等待用户观察
		exit(0);   //结束整个程序
	}
	else
	{
		for (i = 0; i < len; i++) //将数据依次写入文件
		{
			if (parr[i].number != 0)
				fprintf(fp, "姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f \nC语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
		}
	}
	printf("已将学生信息保存在了D盘根目录下的student.bin文件中。\n");
	getch();
	fclose(fp);
	return len;
}
//函数功能：按学号找学生信息
int findnum(struct student *parr, int len)
{
	int number = 0;
	int i;
	printf("请您输入需要查找的学号：");
	scanf("%d", &number);
	for (i = 0; i < len; i++)
	{
		if (number == parr[i].number && parr[i].number != 0)
		{
			printf("姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f C语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
		}
	}
	getch();
	return len;
}
//函数功能：按姓名找学生信息
int findname(struct student *parr, int len)
{
	int i;
	char name[100];
	printf("请您输入需要查找的姓名：");
	scanf("%s", &name);
	for (i = 0; i < len; i++)
	{
		if (strcmp(name, parr[i].name) == 0 && parr[i].number != 0)
			printf("姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f C语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
	}
	getch();
	return len;
}

//函数功能：结束整个程序
void exit(struct student *parr, int len)
{
	char ch = '\0';
	do
	{
		printf("您确定要退出！（y/n）:");
		scanf(" %c", &ch);
	} while ((ch != 'Y') && (ch != 'y') && (ch != 'N') && (ch != 'n'));
	if ((ch == 'Y') || (ch == 'y'))
	{
		exit(0);
	}
	return;
}
//函数功能：修改学生信息
int modify(struct student *parr, int len)
{
	int number = 0;
	char ch = '\0';
	int i;
	printf("请您输入要修改的学生的学号：");
	scanf("%d", &number);
	for (i = 0; i < len; i++)
	{
		if (number == parr[i].number && parr[i].number != 0)
		{
			printf("姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f \nC语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
			printf("您确定要修改该学生信息（y/n）");
			scanf(" %c", &ch);
			if (ch == 'y')
			{
				printf("姓名：");
				scanf("%s", parr[i].name);
				printf("学号：");
				scanf("%d", &parr[i].number);
				printf("学院：");
				scanf("%s", parr[i].collage);
				printf("班级：");
				scanf("%s", parr[i].banji);
				printf("高数成绩:");
				scanf("%f", &parr[i].score1);
				printf("英语成绩：");
				scanf("%f", &parr[i].score2);
				printf("C语言成绩：");
				scanf("%f", &parr[i].score3);
				parr[i].sum = parr[i].score1 + parr[i].score2 + parr[i].score3;
				parr[i].ave = parr[i].sum / 3.0;
				printf("姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f C语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
				printf("修改成功!");
				getch();
			}
			else
			{
				printf("没有找到该学生");
				getch();
				break;
			}
		}
	}
	return len;
}
//函数功能：增加学生信息
int add(struct student *parr, int len)
{
	int i, a, s;
	printf("请输入要加入的学生个数：");
	scanf("%d", &a);
	s = len;
	len = len + a;
	for (i = s; i < len; i++)
	{

		printf("请输入第%d个学生信息：", i + 1);
		printf("姓名：");
		scanf("%s", parr[i].name);
		printf("学号：");
		scanf("%d", &parr[i].number);
		printf("学院：");
		scanf("%s", parr[i].collage);
		printf("班级：");
		scanf("%s", parr[i].banji);
		printf("高数成绩:");
		scanf("%f", &parr[i].score1);
		printf("英语成绩：");
		scanf("%f", &parr[i].score2);
		printf("C语言成绩：");
		scanf("%f", &parr[i].score3);
		parr[i].sum = parr[i].score1 + parr[i].score2 + parr[i].score3;
		parr[i].ave = parr[i].sum / 3.0;
	}
	printf("\n");
	return len;
}
//函数功能：按平均分统计各个分数段的学生人数
int statistics1(struct student *parr, int len)
{

	int a, b, c, d, fail, i;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	fail = 0;
	for (i = 0; i < len; i++)
	{

		if (parr[i].number != 0)
		{
			if (parr[i].ave >= 90 && parr[i].ave <= 100)
				a++;
			if (parr[i].ave >= 80 && parr[i].ave <= 89)
				b++;
			if (parr[i].ave >= 70 && parr[i].ave <= 79)
				c++;
			if (parr[i].ave >= 60 && parr[i].ave <= 69)
				d++;
			if (parr[i].ave >= 0 && parr[i].ave <= 59)
				fail++;
		}
	}
	printf("90~100的人数：%d\n", a);
	printf("80~89的人数：%d\n", b);
	printf("70~79的人数：%d\n", c);
	printf("60~69的人数：%d\n", d);
	printf("不及格的人数：%d\n", fail);
	getch();
	return len;
}
//函数功能：找出3门课程成绩最高的学生，并输出他们的信息
int statistics2(struct student *parr, int len)
{
	int mathmax, englishmax, cmax;
	mathmax = parr[0].score1;
	englishmax = parr[0].score2;
	cmax = parr[0].score3;
	int i;
	for (i = 0; i < len; i++)
	{
		if (parr[i].number != 0)
		{
			if (mathmax < parr[i].score1)
				mathmax = parr[i].score1;
			if (englishmax < parr[i].score2)
				englishmax = parr[i].score2;
			if (cmax < parr[i].score3)
				cmax = parr[i].score3;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (mathmax == parr[i].score1)
			printf("高数最高分学生的信息：\n姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f C语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
		if (englishmax == parr[i].score2)
			printf("英语最高分学生的信息：\n姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f C语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
		if (cmax == parr[i].score3)
			printf("C语言最高分学生的信息：\n姓名：%s 学号：%d 学院：%s 班级：%s 高数成绩：%.2f 英语成绩：%.2f C语言成绩：%.2f 总分：%.2f 平均分：%.2f\n", parr[i].name, parr[i].number, parr[i].collage, parr[i].banji, parr[i].score1, parr[i].score2, parr[i].score3, parr[i].sum, parr[i].ave);
	}
	getch();
	return len;
}
//函数功能：统计3门课程的不及格率
int statistics3(struct student *parr, int len)
{
	int mathfail, englishfail, cfail;
	mathfail = 0;
	englishfail = 0;
	cfail = 0;
	int i, n;
	for (i = 0; i < len; i++)
	{
		if (parr[i].number != 0)
		{
			if (parr[i].score1 < 60)
				mathfail++;
			if (parr[i].score2 < 60)
				englishfail++;
			if (parr[i].score3 < 60)
				cfail++;
			n++;
		}
	}
	printf("数学的不及格率：%d/%d\n", mathfail, n);
	printf("英语的不及格率：%d/%d\n", englishfail, n);
	printf("C语言的不及格率：%d/%d\n", cfail, n);
	getch();
	return len;
}
//函数功能：删除学生信息
int del(struct student *parr, int len)
{
	int i, num;
	printf("请输入要删除学生的学号：");
	scanf("%d", &num);
	for (i = 0; i < len; i++)
	{
		if (parr[i].number == num)

		{
			parr[i].number = 0;
			printf("已删除！！！");
		}
	}

	return len;
}
