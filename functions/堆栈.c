#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct hh
{
    int stack[N];
    int top;
} stack;

int TrimEnd(char *base);
void stackPrint(stack *to);
int stackTop(stack *to);
void stackPush(stack *to, int value);
int stackPop(stack *to);
void stackInit(stack *to);
void traverse(stack *to, int cmpObject, int layer);

void comb(stack *to,int lb, int ub, void (*print)(void))
{
    if(lb<=ub){
        for (; lb <= ub;lb++){
            stackPush(to, lb);
            
        }
    }
    else
        print();
}

void stackInit(stack *to)
{
    memset(to, 0, sizeof(*to));
}

void stackPush(stack *to, int value)
{
    to->stack[to->top] = value;
    to->top++;
}

int stackPop(stack *to)
{
    return to->stack[--to->top];
}

int stackTop(stack *to)
{
    return to->top;
}

void stackPrint(stack *to)
{
    for (int i = 0; i < to->top; i++)
        printf("%d ", to->stack[i]);
    putchar('\n');
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}