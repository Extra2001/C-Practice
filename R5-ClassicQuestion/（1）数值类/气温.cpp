#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	if(t<=9)
	printf("cold"); 
	if(t>=10&&t<=25)
	printf("warm"); 
	if(t>=26)
	printf("hot");
	return 0;
 } 
