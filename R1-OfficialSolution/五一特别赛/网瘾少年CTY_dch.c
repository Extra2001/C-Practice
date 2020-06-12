#include<stdio.h>

char a[20][20]={0};

int main(){
int i,j,ans,m,n;
for ( i = 1; i <=10; i++)
{
    scanf("%s",a[i]+1);
}

for(i=1;i<=10;++i){
    for (j = 1; j <=10; j++)
    {
        ans=0;
        for(m=-1;m<=1;++m){
            for(n=-1;n<=1;++n){
                if(a[m+i][n+j]=='X'){
                    ans++;
                }
            }
        }
        if(ans==0){
            putchar(' ');
        }else if (a[i][j]=='X')
        {
            putchar('X');
        }else
        {
            printf("%d",ans);
        }
        
        
    }
    putchar('\n');
}

}