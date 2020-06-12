#include<stdio.h>

// 00001111   输入 
// 00001000   模 1<<w 
// 00000111   模完后 
// 00000100   和它取&   1<<(w-1) 

// 00000000   后w位取反 
// 00000001   再加1得到相反数 


int main(){
    int w;
    long long a,b,c;
    while (scanf("%lld %lld %d",&a,&b,&w)>0)
    {
        c=a+b;
        c%=(1LLU
		<<w);   // 1LL longlong类型，最后1位是符号。1LLU unsigned long long 没有符号位 
        if(c&(1LLU<<(w-1))){
            c--;
            c^=(1LLU<<w)-1;     // 1000-》0111 
            c=-c;
        }
        printf("%lld + %lld = %lld\n",a,b,c);
    }
    
}
