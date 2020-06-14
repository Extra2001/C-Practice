#include<stdio.h>
int main()
{
	int n,i,a=0;
	scanf("%d",&n);
	struct student
	{
		double num;
		char name[500];
		int math;
		int english;
		int c;
	};
	struct student stu;
    
	
	while(scanf("%lf",&stu.num)!=EOF)
    {
		
		scanf("%s",stu.name); 
		scanf("%d",&stu.math);
		scanf("%d",&stu.english);
		scanf("%d",&stu.c);
		if(stu.math+stu.english+stu.c>270)
		printf("%.0lf %s %d %d %d\n",stu.num,stu.name,stu.math,stu.english,stu.c);
		a=a+1;
		
		if(a==n)
		
		break;
	}
	}

