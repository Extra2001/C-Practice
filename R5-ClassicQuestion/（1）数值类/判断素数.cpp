#include <stdio.h>
#include <math.h>
int  isprime ( int  m) 
{ 	int  i, k;     
	k = sqrt(m);
   	for(i=2; i<=k; i++)
   	{    if(m%i == 0)   
          	return  (0);
	}   
	return  (1);
}
int main(void ) 
{	
	int num, t;
	while(scanf("%d", &num)!=EOF)
	{
	t = isprime(num);
	if (t==1)	
		printf("Yes\n");
	else 	
		printf("No\n");
	
}
}
