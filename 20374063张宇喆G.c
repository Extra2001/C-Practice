#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<stdio.h>
int n;
int a[200005];
int b[200005];
int cmp(const void *a, const void *b)
{
int *c=(int*)a;
int *d=(int*)b;
if(*c>*d)
{return 1;
}
else if(*c<*d)
{
return -1;
}
else
{
return 0;
}
}
int main()
{
int i;
scanf("%d\n", &n);
for(i=1; i<=n; ++i)
{
scanf("%d\n", &a[i]);
b[i]=a[i];
}
qsort(a+1, n, sizeof(a[1]), cmp);
for(i=1; i<=n; i++)
{
 if(b[i]>=a[n-n/10+1]){
  printf("A\n");
 }
 else if(b[i]>=a[n-n/5+1]){
  printf("B\n");
 }
 else if(b[i]<a[n-n/5+1]&&b[i]>=a[n-2*n/5+1]){
  printf("C\n");
 }
 else if(b[i]<a[n-2*n/5+1]&&b[i]>=a[n-4*n/5+1]){
  printf("D\n");
 }
 else{
  printf("F\n");
 }
}
return 0;
}