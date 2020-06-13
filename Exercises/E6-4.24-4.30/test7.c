#include <stdio.h>
#include <string.h>
#define Len 30
int main()
{
	freopen("./in2.txt", "r", stdin);
	char s1[Len], s2[Len];
	int i, j, k, len1, len2;
	gets(s1);
	gets(s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	for (i = 0; i < len1; i++)
	{
		for (j = 0, k = 0; j < len2; j++)
		{
			if (s1[i + j] == s2[j])
				k++;
		}
		if (k == len2)
		{
			printf("%d-%d\n", i, i + len2 - 1);
			i = i + len2 - 1;
		}
	}
	return 0;
}