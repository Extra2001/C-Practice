#include <stdio.h>
#define IN1(a) scanf("%d",&a);
#define IN2(a,b) scanf("%d%d",&a,&b);
#define IN3(a,b,c) scanf("%d%d%d",&a,&b,&c);
#define OUT1(a) printf("%d\n",a);
#define OUT2(a,b) printf("%d%d",a,b);
#define OUT3(a,b,c) printf("%d%d%d",a,b,c);
#define FIN(n,a) for(i=0;i<n;i++){scanf("%d",&a[i]);}
#define FOUT(n,a) for(i=0;i<n;i++){printf("%d\n",a[i]);}
//令人期待的上机
int main() {

	int a,b;
	IN2(a,b);
	if(b==0){
		if(a==4){
			OUT1(1);
			return 0;
		}
		OUT1(0);
		return 0;
	}
	if(a < 4){
		while (a!=4){
			a++;
			b--;
		}
	}
	else if(a > 4){
		while (a!=7){
			a++;
			b--; 
		}
		a = 0;
		while(a!=4){
			a++;
			b--;
		}
	}
	if(b<0){
		OUT1(0);
		return 0;
	}
	OUT1(b/7+1);
	return 0;
}