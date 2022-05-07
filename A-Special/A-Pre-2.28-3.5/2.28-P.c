#include <stdio.h>
#include <string.h>

int main(){
	int n =0;
	scanf("%d\n", &n);
	char a[1000][100], b[1000][100];
	int count = 0;
	for(int i = 0; i < n; i++){
		gets(a[i]);
		if(strstr(a[i],"xxgzbd")){
			for(int j =0;j<100;j++){
				b[count][j] = a[i][j];
			}
			count ++;
		}
	}
	for(int i = 0; i < count; i++){
		printf("%s\n",b[i]);
	}
	return 0;
}