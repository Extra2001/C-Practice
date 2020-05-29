#include <stdio.h>
#include <math.h>
#include <string.h>
//响应净网号召
int main() {
	char s1[1000], s2[1000];
	int i;
	gets(s1);
	gets(s2);
	for(i = 0; i<strlen(s1); i++){
		if(s1[i]>96&&s1[i]<123)
			s1[i] -= 32;
		else if(s1[i]>64&&s1[i]<91){
			s1[i] += 32;
		}
	}
	for(i = 0; i<strlen(s2); i++){
		if(s2[i]>96&&s2[i]<123)
			s2[i] -= 32;
		else if(s2[i]>64&&s2[i]<91){
			s2[i] += 32;
		}
	}
	puts(s1);
	puts(s2);
}