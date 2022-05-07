#include<stdio.h>
#include<math.h>
double f(double x)
{
	return pow(exp(1.0),x)-2;
}
double df(double x)
{
	return pow(exp(1.0),x);
}
int newdon(double (*f)(double x),double (*df)(double x),double x0,double e1,double e2,int max,double *x)
{
	int i;
	double y,d;
	*x=x0;
	for(i=0;i<max;i++)
	{
		y=f(*x);
		d=df(*x);
		if(fabs(d)<e2) return 0;
		d=y/d;
		*x=*x-d;
		if(fabs(d)<e1) return 1;
	}
}
int main()
{
	double ans=0;
	newdon(f(ans),df(ans),0,0.00000000000001,0.0000000001,10,&ans);
	printf("lf",ans);
	return 0;
	
}