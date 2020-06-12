#include<stdio.h>
#include<string.h>
int main() {
    int i, j, N;
    scanf("%d\n", &N);
    char title[100], *loc;
    for (i = 0; i < N; i++) {
        gets(title);
        loc = strstr(title, "xxgzbd");
        if (loc != NULL) {
            printf("%s\n", title);
        }
    }
    return 0;
}
