#include <stdio.h>
int main(void)
{
	int n;
	int num = 6;
	int total = 0; 
	
	scanf("%d",&n);
	while(n--)  //n����0ʱֹͣѭ�� 
	{
		total += num;
		num = num*10 +6;
	}
	printf("%d",total);
	
	return 0;
}
