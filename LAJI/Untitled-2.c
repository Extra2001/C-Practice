// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\zhr买基金\\in6.txt", "r", stdin);
//     int n, cnt = 0;
//     scanf("%d", &n);
//     while (~scanf("%d", &n))
//     {
//         cnt++;
//     }
//     printf("%d", cnt);
// }

// #include <stdio.h>

// int main()
// {
//     freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\zhr买基金\\in6.txt", "r", stdin);
//     freopen("C:\\Users\\jingx\\Documents\\北京航空航天大学\\C助教\\题目\\zhr买基金\\out6.txt", "w", stdout);

//     int n, price, last;
//     long long sum = 0;
//     scanf("%d%d", &n, &last);
//     for (int i = 1; i < n; i++)
//     {
//         scanf("%d", &price);
//         if (price > last)
//             sum += price - last;
//         last = price;
//     }
//     printf("%lld", sum);
// }

// #include <math.h>
// #include <stdio.h>
// int main()
// {
// 	freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
// 	double a = 0, b = 0, c = 0, d = 0, m = 0, n = 0;
// 	char sym = '0';
// 	//printf("hhh");
// 	while (scanf("(%lf%lfi)%c(%lf%lfi)", &a, &b, &sym, &c, &d) != EOF)
// 	{
// 		//printf("hhh");
// 		if (sym == '+')
// 		{
// 			m = a + c;
// 			n = b + d;
// 		}
// 		else if (sym == '-')
// 		{
// 			m = a - c;
// 			n = b - d;
// 		}
// 		else if (sym == '*')
// 		{
// 			m = a * c - b * d;
// 			n = a * d + b * c;
// 		}
// 		else if (sym == '/')
// 		{
// 			m = (a * c + b * d) / (c * c + d * d);
// 			n = (b * c - a * d) / (c * c + d * d);
// 		}
// 		if (fabs(m) < 1e-5)
// 		{
// 			if (fabs(n) < 1e-5)
// 				printf("0\n");
// 			else if (fabs(n - 1) < 1e-5)
// 				printf("i\n");
// 			else if (fabs(n + 1) < 1e-5)
// 				printf("-i\n");
// 			else if (fabs(round(n) - n) < 1e-5)
// 				printf("%.0fi\n", n);
// 			else
// 				printf("%.2fi\n", n);
// 		}
// 		else if (fabs(round(m) - m) < 1e-5)
// 		{
// 			if (fabs(n) < 1e-5)
// 				printf("%.0f\n", m);
// 			else if (fabs(n - 1) < 1e-5)
// 				printf("%.0f+i\n", m);
// 			else if (fabs(n + 1) < 1e-5)
// 				printf("%.0f-i\n", m);
// 			else if (fabs(round(n) - n) < 1e-5 && n > 0)
// 				printf("%.0f+%.0fi\n", m, n);
// 			else if (fabs(round(n) - n) < 1e-5 && n < 0)
// 				printf("%.0f-%.0fi\n", m, -n);
// 			else if (n > 0)
// 				printf("%.0f+%.2fi\n", m, n);
// 			else
// 				printf("%.0f-%.2fi\n", m, -n);
// 		}
// 		else
// 		{
// 			if (fabs(n) < 1e-5)
// 				printf("%.2f\n", m);
// 			else if (fabs(n - 1) < 1e-5)
// 				printf("%.2f+i\n", m);
// 			else if (fabs(n + 1) < 1e-5)
// 				printf("%.2f-i\n", m);
// 			else if (fabs(round(n) - n) < 1e-5 && n > 0)
// 				printf("%.2f+%.0fi\n", m, n);
// 			else if (fabs(round(n) - n) < 1e-5 && n < 0)
// 				printf("%.2f-%.0fi\n", m, -n);
// 			else if (n > 0)
// 				printf("%.2f+%.2fi\n", m, n);
// 			else
// 				printf("%.2f-%.2fi\n", m, -n);
// 		}
// 	}
// 	return 0;
// }

// #include <math.h>
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char t[17];
//     scanf("%s", t);
//     long long k;
//     while (scanf("%lld", &k) != EOF)
//     {
//         long long bias;
//         long long i;
//         long long x = 1;
//         for (i = 1; i <= k - 1; i++)
//         {
//             x = x << 1;
//         }
//         bias = x - 1;
//         long long E = 0;
//         for (i = 1; i <= k; i++)
//         {
//             E *= 2;
//             E += t[i] - '0';
//         }
//         long long delta = E - bias;
//         x = 1;
//         for (i = 1; i <= delta; i++)
//         {
//             x = x << 1;
//         }
//         long long G = 0;
//         for (i = k + 1; i <= strlen(t) - 1; i++)
//         {
//             G *= 2;
//             G += t[i] - '0';
//         }
//         if (t[0] == '0')
//         {
//             printf("%.8lf\n", x + (x * G) / (double)(1 << (strlen(t) - k - 1)));
//         }
//         else
//         {
//             printf("-%.8lf\n", x + (x * G) / (double)(1 << (strlen(t) - k - 1)));
//         }
//     }

//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int a;
//     scanf("%X",&a);
//     printf("%d",a);
// }

// #include <ctype.h>
// #include <stdio.h>
// int main()
// {
//     int C[8];
//     int i, j;
//     int mol;
//     scanf("%X %X %X %X %X %X %X %X", &C[0], &C[1], &C[2], &C[3], &C[4], &C[5], &C[6], &C[7]);
//     int CRC = 0xFFFF, a;
//     for (i = 0; i <= 7; i++)
//     {
//         a = CRC % 0x100;
//         a ^= C[i];
//         CRC = ((CRC >> 8) << 8) + a; //2中的CRC
//         for (j = 1; j <= 8; j++)
//         {
//             mol = CRC % 0x10;
//             CRC /= 0x10; //3中的CRC
//             if (mol == 0x1)
//             {
//                 CRC ^= 0xA001; //4中的检验
//             }
//         }
//     }
//     printf("%X\n", CRC);
//     printf("%02X %02X", CRC % 0x100, CRC / 0x100);
//     return 0;
// }

// #include <stdio.h>

// int main(){
//     printf("%d\n", 5.1 - 3.1);
//     printf("%lf\n", 5.1 - 3.1);
// }

// #include <stdio.h>
// int main()
// {
//     // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
//     unsigned long long a, N, k, b;
//     while (scanf("%llu%llu%llu", &N, &k, &a) != EOF)
//     {
//         k %= N;
//         b = a;
//         a = a << N;
//         a = a | b;
//         a = a >> (N - k);
//         long long sum = 1;
//         for (int j = 1; j <= N; j++)
//         {
//             sum *= 2;
//         }
//         sum -= 1;
//         a = a & sum;
//         printf("%llu\n", a);
//     }

//     return 0;
// }

// #include <stdio.h>
// #define ll long long
// int T;
// double x, y, R, x0, y0;
// ll toLL(double x)
// {
//     if (x > 0)
//         return (x * 10000 + 0.0001);
//     else
//         return (x * 10000 - 0.0001);
// }
// int main(void)
// {
//     scanf("%d", &T);
//     while (T--)
//     {
//         scanf("%lf%lf%lf%lf%lf", &x, &y, &R, &x0, &y0);
//         ll X = toLL(x), Y = toLL(y), r = toLL(R), X0 = toLL(x0), Y0 = toLL(y0);
//         if ((X0 - X) * (X0 - X) + (Y0 - Y) * (Y0 - Y) <= r * r)
//             puts("YES");
//         else
//             puts("NO");
//     }
//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int a = 1;
//     a <<= 31;
//     a += 1;
//     printf("%d\n%u", a, a);
// }