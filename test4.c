#include <stdio.h >
int main()
{
	int n ,a,b,c;
	scanf ("%d", &n);
	while (n>0)
	{
		int max, om,min;
		scanf("%d %d %d", &a,&b,&c);
		if (a > b)
		{
			max = a;
			om = b;
			min =b;
		}
		else 
		{
			max = b;
			min = a;
			om = a;
		}
		if (max > c)
		{
			if (c > min) om = c;
		}
		else 
		{
			om = max;
			max =c;
		}
		if (max*max == min*min+om*om) printf ("YES\n");
		else printf ("NO");
		n--;
	}
	return 0;
 } 
