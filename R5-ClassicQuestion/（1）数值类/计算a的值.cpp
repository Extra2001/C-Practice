#include<stdio.h>
#include<math.h> 
 int main()
 { double a,b1,b2=1,c1,c2=1,d1,d2=1;
   for(b1=1;b1<=5;b1++)
   {b2=b1*b2;
   }
   for(c1=1;c1<=3;c1++)
   {c2=c1*c2;
   }
   for(d1=1;d1<=2;d1++)
   {d2=d1*d2;
   }
   a=b2/(c2*d2);
   printf("%lf",a);
 }
