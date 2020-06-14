#include<stdio.h>
int main()
{
	int tall;
	scanf("%d",&tall);
	if(tall>=0&&tall<=155)
	printf("low");
	if(tall>=156&&tall<=175)
	printf("moderate");
	if(tall>=176)
	printf("high");
	return 0;
 } 
