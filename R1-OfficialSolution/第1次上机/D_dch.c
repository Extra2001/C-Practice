#include <stdio.h>
#include <math.h> //���ÿ����ź���sqrt()�͸���������ֵ����fabs()

// ��Ҫһ�����͵����η��̴���
// ��һ������a   aΪ0��һ�η���
// �ڶ�������delta  
// ������������С�������

//  

int main()
{
    double a, b, c,x1,x2,tmp;                         //Ϊ�������ʵ���⣬��double����int
    while (scanf("%lf%lf%lf", &a, &b, &c)>0) // while(scanf()>0)���ڶ�����������
    {
        if (fabs(a) < 1e-6) // a = 0�����̱�Ϊ b/x + c = 0
        {
            if (fabs(b) < 1e-6) // b = 0�����̱�Ϊ c = 0 �޽�
                printf("NO Solution\n");     // ƴд���� 
            else
                printf("%.2f\n", -b / c);
        }
        else //a��Ϊ0�����̼�cx^2 + bx + a = 0
        {
            double delta = b * b - 4.0 * a * c; // ����delta    �����ʹ��int����a��bc��b*b������� 
            
			if (fabs(delta) < 1e-6) // delta = 0�����ҽ���1��
			{
				printf("%.2f\n", -b / (2 * c));
			}
                
			
            else if (delta < 0.0)
            {
            	printf("NO Solution\n");
			}
                
            else //������
            {
                x1 = (-b - sqrt(delta)) / (2 * c);
                x2 = (-b + sqrt(delta)) / (2 * c);
                if (x1 > x2) // ��x1���󣬽������������
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
