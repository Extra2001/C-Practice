#include<stdio.h>

long long mi[10005]={0};  // 大数组要放到全局 
int main(){
    char c;
    int n,p,i;
    while (scanf("%d%c%d",&n,&c,&p)>0)
    {
        mi[p]+=n;
    }

    for(i=0;i<10003;++i){
        if(mi[i]){
        printf("%+lld%c%d",mi[i],c,i);
        }
    }
    
}
