#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//摔跤比赛
int judge(int a, int b) { //辗转相除法判断最大公约数
	if (a == 1 || b == 1 || b == -1 || a == -1) {
		return 1;
	}
	if (a == 0 || b == 0) {
		return 0;
	}
	if (a == b) {
		return 0;
	}
	int t = a % b;
	while (t) {
		a = b;
		b = t;
		t = a % b;
	}
	if (abs(b) == 1) {
		return 1;//互质
	}
	else {
		return 0;//不是互质
	}
}

int third(int select1, int select2, int select, int a[], int b[], int v[]) {//A队第三个数匹配
	int i;
	for (i = 0; i < 4; i++) {
		if (i == select || i == select1 || i == select2) {
			continue;
		}
		if (!judge(a[3], b[i])) {//给结果数组赋值
			v[0] = b[select1];
			v[1] = b[select2];
			v[2] = b[select];
			v[3] = b[i];
			return 1;
		}
	}
	return 0;
}

int second(int select1, int select, int a[], int b[], int v[]) {//A队第二个数
	int i;
	for (i = 0; i < 4; i++) {
		if (i == select || i == select1) {
			continue;
		}
		if (!judge(a[2], b[i])) {
			if (third(select1, select, i, a, b, v)) {
				return 1;
			}
		}
	}
	return 0;
}

int first(int select, int a[], int b[], int v[]) {//A队第一个数
	int i;
	for (i = 0; i < 4; i++) {
		if (i == select) {
			continue;
		}
		if (!judge(a[1], b[i])) {
			if (second(select, i, a, b, v)) {
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	//freopen("C:\\Users\\Lenovo\\Projects\\C语言程序设计\\Debug\\in.txt", "r", stdin);
	int i, n, j = 0, flag = 1;
	int a[4], b[4], v[4], s[4] = { 0 };
	while (~scanf("%d", &a[0])) {
		for (i = 1; i < 4; i++) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < 4; i++) {
			scanf("%d", &b[i]);
		}
		for (j = 0; j < 4; j++) {
			if (!judge(a[0], b[j])) {//把所有不是互质的结果都计算一遍 列出所有路径
				if (first(j, a, b, v)) {
					flag = 1;
					break;
				}
				else {
					flag = 0;
				}
			}
			else {
				flag = 0;
			}
		}
		if (flag) {
			for (i = 0; i < 4; i++) {
				printf("%dvs%d\n", a[i], v[i]);
			}
		}
		else {
			printf("As we can't.\n");
		}
	}
	//fclose(stdin);
}