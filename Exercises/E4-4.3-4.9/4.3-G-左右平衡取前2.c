#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这个勇者确实很菜所以过分慎重
int a[255];

int main() {
    int i, n;
    a[1] = 1;
    a[2] = 3;
    for (i = 3; i < 251;i++){
        a[i] = (a[i - 1] + 2 * a[i - 2]) % 1000007;
    }
    while(~scanf("%d", &n)){
        printf("%d\n", a[n]);
    }
}