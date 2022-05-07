#include <stdio.h>

int main()
{
	int n, sum=0, i = 0;
	scanf("%d", &n);
	int a,b,c,d = 0;
	int a1 =0 ,b1=0,c1=0,d1 = 0;
	char x;
	while(i < n){
		x = getchar();
		if(x == 'A'){
			scanf("%d", &a);
			if(a>40 && a1==0){
			sum += a - 40;
		}
		else if(a > 40 && a1 != 0){
			sum += a - 40 + a1;
			a1 = 0;
		}
		else if(a<40&&a+a1>40){
			sum += a+a1-40;
			a1 = 0;
		}
		else{
			a1 += a;
		}
		
		}
		else if(x == 'B'){
			scanf("%d", &b);
			if(b>30 && b1==0){
			sum += b - 30;
		}
		else if(b > 30 && b1 != 0){
			sum += b - 30 + b1;
			b1 = 0;
		}
		else if(b<30&&b+b1>30){
			sum += b+b1-30;
			b1 = 0;
		}
		else{
			b1 += b;
		}
		
		}
		else if(x == 'C'){
			scanf("%d", &c);
			if(c>35 && c1==0){
			sum += c - 35;
		}
		else if(c > 35 && c1 != 0){
			sum += c - 35 + c1;
			c1 = 0;
		}
		else if(c<35&&c+c1>35){
			sum += c+c1-35;
			c1 = 0;
		}
		else{
			c1 += c;
		}
		
		}
		else if(x == 'D'){
			scanf("%d", &d);
			if(d>20 && d1==0){
			sum += d - 20;
		}
		else if(d > 20 && d1 != 0){
			sum += d - 20 + d1;
			d1 = 0;
		}
		else if(d<20&&d+d1>20){
			sum += d + d1-20;
			d1 = 0;
		}
		else{
			d1 += d;
		}
		
		}
		else if(x == 'N'){
			i++;
		}
	}
	printf("%d",sum);
	return 0;
}