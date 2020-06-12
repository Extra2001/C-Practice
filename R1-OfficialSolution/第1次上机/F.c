#include<stdio.h>

int main(){
	
	char c;
	
	while((c=getchar())!='\n'){
		if(c>='A'&&c<='Z'){
			printf("%c",c+32);
		}
		else if(c>='a'&&c<='z'){
			printf("%c",c-32);
		}
		else{
			printf("%c",c);
		}
	}
	printf("\n");
	for(int i;i<=4;i++){
		c=getchar();
		if(c>='A'&&c<='Z'){
			printf("%c",c+32);
		}
		else if(c>='a'&&c<='z'){
			printf("%c",c-32);
		}
		else{
			printf("%c",c);
		}
	}
	
	return 0;
}
