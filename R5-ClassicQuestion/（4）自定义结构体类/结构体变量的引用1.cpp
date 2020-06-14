#include<stdio.h>
int main()
{
	struct student
	{
		double num;
		char name[50];
		int old;
		int s1;
		int s2;
		int s3; 
	};
	struct student stu[100];
	int i;
	for(i=0;i<100;i++)
	{
	    scanf("%lf",&stu[i].num);
        scanf("%s",&stu[i].name); 
		scanf("%d %d %d %d",&stu[i].old,&stu[i].s1,&stu[i].s2,&stu[i].s3);
	}
	for(i=0;i<100;i++)
	{
		if(stu[i].num==0)
		break;
		else
		printf("%0.0lf %d\n",stu[i].num,stu[i].s1+stu[i].s2+stu[i].s3);
	}

}	

