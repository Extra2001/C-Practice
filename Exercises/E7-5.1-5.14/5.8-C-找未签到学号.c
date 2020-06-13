#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[20];
    int id;
    int isChecked;
} stu;

stu a[515];

int search(int id, int n, int start){
    for (int i = start; i < n;i++){
        if(a[i].id == id){
            return i;
        }
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;i++){
        scanf("%s%d", a[i].name, &a[i].id);
        a[i].isChecked = 0;
    }
    int tmp;
    for (int i = 0; i < m;i++){
        scanf("%d", &tmp);
        int index = search(tmp, n, i);
        a[index].isChecked = 1;
    }
    for (int i = 0; i < n;i++){
        if(a[i].isChecked==0){
            puts(a[i].name);
        }
    }
    // fclose(stdin);
}