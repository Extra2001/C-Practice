#include<stdio.h>
main()
{
	struct student  //�Զ�����Ϊstudent�Ľṹ��
	{
		int year,mouth,day;  //�����ն���Ϊint 
		double number;  //ѧ�Ŷ���Ϊdouble 
		char name [100];  //���ֶ���Ϊ�ַ��͵����� 
	}st1;  // ������st1���滻student�������д 
	while(scanf("%lf",&st1.number)!=EOF)
	{
		scanf(" %s %d.%d.%d",&st1.name,&st1.year,&st1.mouth,&st1.day);  //���� 
		getchar();  //�ȴ��¸����룬���ⰴ������ͣ�����������������ʵ��scanf��printf֮���ͣ��������û�����ã����ԴӼ����Ͻ��ܵ����ݲ��ḳֵ���κα��� 
		printf("%.0lf\n",st1.number);  //��ӡnumber�������� st1. ��������Ҫ��������� 
		puts(st1.name);  //����puts��������ַ��� 
		printf("%04d.%02d.%02d\n",st1.year,st1.mouth,st1.day);  //�ֱ����ò�ͬ���ȵ���� 
	}
}
