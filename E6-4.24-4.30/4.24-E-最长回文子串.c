#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[105];

int isHuiwen(char* p, int n)
{
	char* s = (char*)malloc(sizeof(a));
	strcpy(s, p);
	s[n] = '\0';
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	// freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
	int q;
	scanf("%d", &q);
	gets(a);
	for (int i = 0; i < q; i++)
	{
		gets(a);
		int count = 0;
		int len = strlen(a);
		for (int j = 0; j < len; j++)
		{
			char* p = a + j;
			for (int k = len - 1; k >= 0; k--)
			{
				if (k - j < 0) {
					break;
				}
				if (isHuiwen(p, k - j + 1))
				{
					if (k - j + 1 > count)
					{
						count = k - j + 1;
					}
				}
			}
		}
		printf("%d\n", count);
	}

	//fclose(stdin);
}