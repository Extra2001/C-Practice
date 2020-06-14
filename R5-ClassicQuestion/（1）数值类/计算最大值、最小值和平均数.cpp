#include<stdio.h>
int main()
{int a,b,c,max1,max2,min1,min2,ave;
scanf("%d %d %d",a,b,c);
if(a>b) max1=a;
else max1=b;
if(max1<c) max2=c;
if(a>b) min1=b;
else min1=a;
if(min1>c) min2=c;
ave=(a+b+c)/3;
printf("max=%d min=%d ave=%d",max2,min2,ave);
}
