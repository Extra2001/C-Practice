#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int rad[500000];

int com(const void*a,const void *b){
    return (*(int *)b - *(int *)a);
}

int main(){
    freopen("./in3.txt", "w", stdout);
    for (int i = 0; i < 500000;i++){
        // rad[i] = rand() * 30518;
        rad[i] = 1;
    }
    qsort(rad, 500000, sizeof(int), com);
    for (int i = 0; i < 500000;i++){
        printf("%d ", rad[i]);
    }
    fclose(stdout);
    // printf("%lf", 1e9 / RAND_MAX);
    // printf("%d", RAND_MAX);
}