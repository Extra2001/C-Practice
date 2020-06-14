#include<stdio.h> 
int main()
{
int i,m,n,t;
printf("请输入两个数：");
scanf("%d %d",&m,&n);
if(m>n)
{t=m;m=n;n=t;}
for(i=m;i>0;i--)
if(m%i==0&n%i==0)
{printf("最大公约数为：%d ",i);
break;}
for(i=1;i<=m;i++)
if(n*i%m==0)
{printf("\n");
printf("最小公倍数为：%d",n*i);
break;}
}
