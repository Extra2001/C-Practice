#include <stdio.h>
double GPA(int n)
{
    double m;
    if (n >= 0 && n < 60)
        m = 0;
    else
        m = 4 - 3.0 / 1600.0 * (100 - n) * (100 - n);
    return m;
}
int score;
double credit;
int main()
{
    freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    double sum_grade, sum_point;
    while (scanf("%d%lf", &score, &credit) != EOF)
    {
        sum_grade += GPA(score) * credit;
        sum_point += credit;
    }
    printf("%.2f\n", sum_grade / sum_point);
    return 0;
}