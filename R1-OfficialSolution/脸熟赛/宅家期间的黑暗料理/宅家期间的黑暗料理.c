#include<stdio.h>

int main()
{
	int n,i,a[25];//������ʹ��a[n+1]���Ƶķ�ʽ������ԭ���ں����˵�� 

	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	int sum=0;
	for (i=1;i<=n;i++) sum+=(n+1-i)*a[i];//�൱��sum=sum+i*a[i]
	printf("%d",sum);
	
	return 0; 
} 
