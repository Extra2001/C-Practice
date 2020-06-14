#include<stdio.h>
int main()
{
	struct date
	{
		int year;
		int month;
		int day;
	};
	struct date d[100];
	
	
	struct student
	{
		double num;
		char name[50];
	};
	struct student stu[100];
	int i;
	for(i=0;i<100;i++)
	{
	    scanf("%lf",&stu[i].num);
        scanf("%s",&stu[i].name); 
		scanf("%d.%d.%d",&d[i].year,&d[i].month,&d[i].day);
	}
	for(i=0;i<100;i++)
	{
		if(stu[i].num==0)
		break;
		else
		printf("%0.0lf\n%s\n%02d.%02d.%02d\n",stu[i].num,stu[i].name,d[i].year,d[i].month,d[i].day);
	}

}	

