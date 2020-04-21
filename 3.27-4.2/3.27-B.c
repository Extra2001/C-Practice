#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Switch真香
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}

void clear(char a[], char b[], char c[]) {
	for (int i = 0; i < 20; i++) {
		a[i] = '\0';
		b[i] = '\0';
		c[i] = '\0';
	}
}
int main()
{
	double a, b,sum;
	char op;
	char in[20], o1[20], o2[20];
	int c1=0, c2=0, flag=0;
	while (~scanf("%s", &in)) {
		c1 = c2 = flag = 0;
		int i = strlen(in);
		for (int j = 0; j < i; j++) {
			switch (in[j])
			{
			case '+':
			case '-':
			case '*':
			case '/':
				op = in[j];
				flag = 1;
				break;
			default:
				if (flag) {
					o2[c2] = in[j];
					c2++;
				}
				else {
					o1[c1] = in[j];
					c1++;
				}
				break;
			}
		}
		a = atof(o1);
		b = atof(o2);
		switch (op)
		{
		case '+':
			sum = a + b;
			break;
		case '-':
			sum = a - b;
			break;
		case '*':
			sum = a * b;
			break;
		case '/':
			if (fabs(b) < 1e-10) {
				printf("Wrong Input\n");
				clear(o1, o2, in);
				continue;
			}
			sum = a / b;
			break;
		default:
			break;
		}
		printf("%.2lf\n", sum);
		clear(o1, o2, in);
	}
}