#include<stdio.h>

int main(){
    int m,n,i,j;
    int a[40][40]={0};
    int x1,x2,y1,y2,temp;
    scanf("%d %d",&m,&n);

    for(i=1;i<=m;i++){
        for(j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
        }
    }

    while (scanf("%d %d %d %d",&x1,&y1,&x2,&y2)>0)
    {
        temp=a[x1][y1];
        a[x1][y1]=a[x1+x2][y1+y2];
        a[x1+x2][y1+y2]=temp;
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;++j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}