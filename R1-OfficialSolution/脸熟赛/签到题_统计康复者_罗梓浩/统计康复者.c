#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100];
	char s2[100]; 
	scanf("%s", &s1);
	scanf("%s", &s2);
	strcat(s1, "/");
	strcat(s1, s2);
	printf("%s\n", s1);
	return 0;
}
