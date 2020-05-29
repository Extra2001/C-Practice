#include <stdio.h>
//Zeller 求星期
int main()
{
	// c: century-1, y: year, m:month, w:week, d:day
	int c, y, m, w, d, longday = 1;
	int fff = -1;
	while (~scanf("%d", &longday))
	{
		if (longday == -1)
			break;
		if (!(longday >= 101 && longday <= 99991231))
		{
			printf("Wrong input format, try again!\n");
			continue;
		}
		if (longday >= 15821005 && longday <= 15821014)
		{
			printf("Nonexistent date!\n");
			continue;
		}
		if(longday<15821005){
			fff = 2;
		}
		else {
			fff = -1;
		}
		y = longday / 10000;
		m = (longday % 10000) / 100;
		d = longday % 100;
		if (m < 3)
		{
			y = y - 1;
			m = m + 12;
		}
		c = y / 100;
		y = y % 100;

		// Zeller formula
		w = (y + y / 4 + c / 4 - 2 * c + (26 * (m + 1)) / 10 + d +fff) % 7;
		if (w < 0)
			w += 7;
		switch (w)
		{
		case 0:
			printf("Sun\n");
			break;
		case 1:
			printf("Mon\n");
			break;
		case 2:
			printf("Tue\n");
			break;
		case 3:
			printf("Wed\n");
			break;
		case 4:
			printf("Thu\n");
			break;
		case 5:
			printf("Fri\n");
			break;
		case 6:
			printf("Sat\n");
			break;
		}
	}
	return 0;
}