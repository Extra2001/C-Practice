#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[105][10];
int shang[10] = {0};

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int m, n, youxiu[10] = {0};
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            shang[j] += a[i][j];
            if (a[i][j] >= 80)
            {
                youxiu[j]++;
            }
        }
    }
    for (int i = 0; i < n;i++){
        printf("%.2lf ", (double)shang[i] / m);
    }
    printf("\n");
    for (int i = 0; i < n;i++){
        printf("%.2lf%% ", ((double)youxiu[i] / (double)m)*100);
    }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        printf("%.2lf\n", (double)sum / (double)n);
        }

    // fclose(stdin);
}