#include<stdio.h> 
int main()
{
int i,m,n,t;
printf("��������������");
scanf("%d %d",&m,&n);
if(m>n)
{t=m;m=n;n=t;}
for(i=m;i>0;i--)
if(m%i==0&n%i==0)
{printf("���Լ��Ϊ��%d ",i);
break;}
for(i=1;i<=m;i++)
if(n*i%m==0)
{printf("\n");
printf("��С������Ϊ��%d",n*i);
break;}
}
