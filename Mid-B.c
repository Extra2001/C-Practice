#include<stdio.h>

int main(){
    double sum = 0, tmp;
    int cnt = 0;
    while(~scanf("%lf", &tmp)){
        sum += tmp;
        cnt++;
    }
    printf("%.2lf", sum / cnt);
}