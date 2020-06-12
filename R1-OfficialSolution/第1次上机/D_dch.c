#include <stdio.h>
#include <math.h> //调用开根号函数sqrt()和浮点数绝对值函数fabs()

// 不要一上来就当二次方程处理
// 第一步——a   a为0，一次方程
// 第二步——delta  
// 第三步——从小到大输出

//  

int main()
{
    double a, b, c,x1,x2,tmp;                         //为方便计算实数解，用double代替int
    while (scanf("%lf%lf%lf", &a, &b, &c)>0) // while(scanf()>0)用于多组数据输入
    {
        if (fabs(a) < 1e-6) // a = 0，方程变为 b/x + c = 0
        {
            if (fabs(b) < 1e-6) // b = 0，方程变为 c = 0 无解
                printf("NO Solution\n");     // 拼写错误 
            else
                printf("%.2f\n", -b / c);
        }
        else //a不为0，方程即cx^2 + bx + a = 0
        {
            double delta = b * b - 4.0 * a * c; // 计算delta    如果你使用int定义a和bc，b*b会溢出， 
            
			if (fabs(delta) < 1e-6) // delta = 0，有且仅有1解
			{
				printf("%.2f\n", -b / (2 * c));
			}
                
			
            else if (delta < 0.0)
            {
            	printf("NO Solution\n");
			}
                
            else //有两解
            {
                x1 = (-b - sqrt(delta)) / (2 * c);
                x2 = (-b + sqrt(delta)) / (2 * c);
                if (x1 > x2) // 若x1更大，交换二者再输出
                {
                    tmp = x1;
                    x1 = x2;
                    x2 = tmp;
                }
                printf("%.2f %.2f\n", x1, x2);
            }
        }
    }
    return 0;
}
