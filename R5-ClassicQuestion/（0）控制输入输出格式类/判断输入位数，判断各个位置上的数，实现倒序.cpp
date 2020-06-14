#include<stdio.h>
main()
{
	//赋初值给整数和各个位上的数，默认值为0 
	int s,s1,s2,ge,shi,bai,qian,wan,order;
	//给位数赋初值为1，数的位数不能设为0，不存在位数为零的数 
	int dight=1;
	printf("请输入一个不多于5位的正整数：");
	scanf("%d",&s);
	s1=s;
	s2=s1;
	//判断位数 
	while(s1>=10)
	{
	    dight++;
	    s1=s1/10;
	}
	//判断每一位的数字 
	if(dight==5)//如果是五位数 
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
   if(dight==4)//如果是四位数 
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
   if(dight==3)//如果是三位数 
	{
		ge=s2%10;
		s2=s2/10;
		shi=s2%10;
		s2=s2/10;
		bai=s2%10;
		order=bai+shi*10+ge*100;
	 } 
   if(dight==2)//如果是两位数 
	{
		ge=s2%10;
		s2=s2/10;
		shi=s2%10;
		order=shi+ge*10;
	 }
   if(dight==1)//如果是个位数 
	{
        ge=s2;
		order=ge; 
	 }
	 printf("输入的数为：%d\n",s);		 		
	//输出位数 
	printf("这是一个%d位数\n",dight);
	//输出每一位
	if(dight==5) printf("个位数为：%d,十位数为：%d,百位数为：%d,千位数为：%d,万位数为：%d\n",ge,shi,bai,qian,wan);
	if(dight==4) printf("个位数为：%d,十位数为：%d,百位数为：%d,千位数为：%d\n",ge,shi,bai,qian);
	if(dight==3) printf("个位数为：%d,十位数为：%d,百位数为：%d\n",ge,shi,bai);
	if(dight==2) printf("个位数为：%d,十位数为：%d",ge,shi);
	if(dight==1) printf("个位数为：%d\n",ge);
	printf("逆序为%d",order);
	} 
	
	
