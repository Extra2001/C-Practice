#include<stdio.h>

int main(){
	char c;
	double a,b,r;
	while(scanf("%lf%c%lf",&a,&c,&b)>0){
		switch(c){
			case '+':r=a+b;break;
			case '-':r=a-b;break;
			case '*':r=a*b;break;
			case '/':
				if(b<=1e-6 && b>=-1e-6){
					printf("Wrong Input\n");
					continue;
				}else{
					r=a/b;
				}
		}
		printf("%0.2f\n",r);
	}
	return 0;
}
