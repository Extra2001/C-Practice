#include<stdio.h>

// 00001111   ���� 
// 00001000   ģ 1<<w 
// 00000111   ģ��� 
// 00000100   ����ȡ&   1<<(w-1) 

// 00000000   ��wλȡ�� 
// 00000001   �ټ�1�õ��෴�� 


int main(){
    int w;
    long long a,b,c;
    while (scanf("%lld %lld %d",&a,&b,&w)>0)
    {
        c=a+b;
        c%=(1LLU
		<<w);   // 1LL longlong���ͣ����1λ�Ƿ��š�1LLU unsigned long long û�з���λ 
        if(c&(1LLU<<(w-1))){
            c--;
            c^=(1LLU<<w)-1;     // 1000-��0111 
            c=-c;
        }
        printf("%lld + %lld = %lld\n",a,b,c);
    }
    
}
