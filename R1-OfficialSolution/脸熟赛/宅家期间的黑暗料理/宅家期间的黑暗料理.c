#include<stdio.h>

int main()
{
	int n,i,a[25];//不建议使用a[n+1]类似的方式声明，原因在后面会说到 

	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	int sum=0;
	for (i=1;i<=n;i++) sum+=(n+1-i)*a[i];//相当于sum=sum+i*a[i]
	printf("%d",sum);
	
	return 0; 
} 
