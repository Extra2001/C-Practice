#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[50];

int N, M, T;
int selected[50];
int outed = 0;

int desea(int layer, long long cursum)
{
    if (layer >= M)
    {
        if (cursum >= T)
        {
            for (int i = 0; i < M; i++)
            {
                printf("%d ", selected[i]);
            }
            printf("\n");
            outed++;
        }
    }
    else
    {
        for (int i = selected[layer - 1]; i < N; i++)
        {
            int flag = 1;
            for (int j = 0; j < layer; j++)
            {
                if (selected[j] == i + 1)
                    flag = 0;
            }
            selected[layer] = i + 1;
            desea(layer + 1, cursum + x[i]);
        }
    }
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);

    scanf("%d%d%d", &N, &M, &T);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
    }
    desea(0, 0);
    if (outed == 0)
    {
        printf("Sorry, teacher.");
    }
    // fclose(stdin);
}