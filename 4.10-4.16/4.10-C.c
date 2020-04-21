#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, a, count = 0,i;
    while(~scanf("%d", &n)){
        count = 0;
        for (i = 0; i < n;i++){
            scanf("%d", &a);
            if(a==i+1){
                count++;
            }
        }
        printf("%d\n", count);
    }
    // fclose(stdin);
}