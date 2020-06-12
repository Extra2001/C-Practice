#include <stdio.h>
#include<math.h>

//16*atan()-4*atan()
// 16*(x-x+x-x)-4*(x....x)
// (16*x1-4*x2)+(16*(-x)**3/3-4*...)++
// ** 不是c语言里的符号

int main()
{
    int sig;
    int n, i;
    double ans;

    while (scanf("%d", &n)>0)
    {
        ans = 0.0;   ///初始化
        
        for (i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                continue;
            }
            else if (i % 4 == 1)
            {
                sig = 1;
            }
            else
            {
                sig = -1;
            }
            ans+=sig*(16.0*pow(1.0/5,i)/i-4.0*pow(1.0/239,i)/i);
            // ^表示异或，不表示次方，pow输入输出都是double
            // 1/5==0，1.0/5==0.2
        }
        printf("%.9f\n",ans);
    }
}