#include<stdio.h>
main()
{
	//����ֵ�������͸���λ�ϵ�����Ĭ��ֵΪ0 
	int s,s1,s2,ge,shi,bai,qian,wan,order;
	//��λ������ֵΪ1������λ��������Ϊ0��������λ��Ϊ����� 
	int dight=1;
	printf("������һ��������5λ����������");
	scanf("%d",&s);
	s1=s;
	s2=s1;
	//�ж�λ�� 
	while(s1>=10)
	{
	    dight++;
	    s1=s1/10;
	}
	//�ж�ÿһλ������ 
	if(dight==5)//�������λ�� 
	{
		ge=s2%10;
		s2=s2/10;
		shi=s2%10;
		s2=s2/10;
		bai=s2%10;
		s2=s2/10;
		qian=s2%10;
		s2=s2/10;
		wan=s2%10;
		order=wan+qian*10+bai*100+shi*1000+ge*10000;
	 } 
   if(dight==4)//�������λ�� 
	{
		ge=s2%10;
		s2=s2/10;
		shi=s2%10;
		s2=s2/10;
		bai=s2%10;
		s2=s2/10;
		qian=s2%10;
		order=qian+bai*10+shi*100+ge*1000;
	 } 	
   if(dight==3)//�������λ�� 
	{
		ge=s2%10;
		s2=s2/10;
		shi=s2%10;
		s2=s2/10;
		bai=s2%10;
		order=bai+shi*10+ge*100;
	 } 
   if(dight==2)//�������λ�� 
	{
		ge=s2%10;
		s2=s2/10;
		shi=s2%10;
		order=shi+ge*10;
	 }
   if(dight==1)//����Ǹ�λ�� 
	{
        ge=s2;
		order=ge; 
	 }
	 printf("�������Ϊ��%d\n",s);		 		
	//���λ�� 
	printf("����һ��%dλ��\n",dight);
	//���ÿһλ
	if(dight==5) printf("��λ��Ϊ��%d,ʮλ��Ϊ��%d,��λ��Ϊ��%d,ǧλ��Ϊ��%d,��λ��Ϊ��%d\n",ge,shi,bai,qian,wan);
	if(dight==4) printf("��λ��Ϊ��%d,ʮλ��Ϊ��%d,��λ��Ϊ��%d,ǧλ��Ϊ��%d\n",ge,shi,bai,qian);
	if(dight==3) printf("��λ��Ϊ��%d,ʮλ��Ϊ��%d,��λ��Ϊ��%d\n",ge,shi,bai);
	if(dight==2) printf("��λ��Ϊ��%d,ʮλ��Ϊ��%d",ge,shi);
	if(dight==1) printf("��λ��Ϊ��%d\n",ge);
	printf("����Ϊ%d",order);
	} 
	
	
