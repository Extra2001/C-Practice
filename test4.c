
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    freopen("matrix.txt", "w", stdout);
    int A[16][16], B[16][16], C[16][16];
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    for (int i = 0; i < 16; i++)
    {
        A[i][i] = 1;
        B[i][i] = 1;
    }
    for (int i = 0; i < 5626596; i++)
        rand();
    int opa[10000], opb[10000], opc[10000];
    for (int i = 0; i < 100; i++)
    {
        opa[i] = rand() % 16;
        opb[i] = rand() % 16;
        if (opa[i] == opb[i])
            continue;
        opc[i] = rand() % 11 - 5;
        if (opc[i] == 0)
            continue;
        for (int j = 0; j < 16; j++)
            A[opa[i]][j] += A[opb[i]][j] * opc[i];
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            printf("%d ", A[i][j]);
        // printf("%d", rand());
        printf("\n");
    }
    printf("=============================================\n");
    for (int i = 99; i >= 0; i--)
    {
        if (opc[i] == 0 || opa[i] == opb[i])
            continue;
        for (int j = 0; j < 16; j++)
            B[opa[i]][j] -= B[opb[i]][j] * opc[i];
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    printf("=============================================\n");
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            for (int k = 0; k < 16; k++)
                C[i][j] += A[i][k] * B[k][j];
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("=============================================\n");
    fclose(stdout);
    return 0;
}