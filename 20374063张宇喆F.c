#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
 {
  unsigned int a,b;
  int m,n;
  while(~scanf("%ud %d %d",&a,&m,&n)){
   b=(a^(2^(n-1)-2^(m-1)));
   printf("%ud",b);
  }
 return 0;
}
