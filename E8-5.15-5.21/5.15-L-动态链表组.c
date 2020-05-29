#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ta
{
    char value[20];
    struct ta *next;
} table;

table *head[1000005], *end[1000005];
// table *head[105], *end[105];

int a, b;
char s[20];

int TrimEnd(char *base);
int readLine();
void init(int index);
int isEmpty(int index);
void insertOne(int index, char *value);
void deleteOne(int index, int toDel);
void concat(int destIndex, int fromIndex);
void outPut(int index);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        init(i);

    for (int i = 0; i < m; i++)
    {
        int op = readLine();
        switch (op)
        {
        case 1:
            deleteOne(a, 0);
            break;
        case 2:
            insertOne(a, s);
            break;
        case 3:
            concat(b, a);
            break;
        case 4:
            outPut(a);
            break;
        default:
            break;
        }
    }
    // fclose(stdin);
}

int readLine()
{
    int op;
    scanf("%d%d", &op, &a);
    switch (op)
    {
    case 1:
        return op;
    case 2:
        scanf("%s", s);
        return op;
    case 3:
        scanf("%d", &b);
        return op;
    case 4:
        return op;
    default:
        return 0;
    }
}

void init(int index)
{
    head[index] = (table *)malloc(sizeof(table));
    head[index]->next = NULL;
    end[index] = head[index];
}

int isEmpty(int index)
{
    if (end[index] == head[index])
        return 1;
    else
        return 0;
}

void insertOne(int index, char *value)
{
    end[index]->next = (table *)malloc(sizeof(table));
    end[index] = end[index]->next;
    strcpy(end[index]->value, value);
    end[index]->next = NULL;
}

void deleteOne(int index, int toDel)
{
    if (isEmpty(index))
        return;
    table *p = head[index], *l = NULL;
    for (int i = 0; i < toDel; i++)
    {
        l = p;
        p = p->next;
    }
    if (l == NULL)
    {
        head[index] = head[index]->next;
        // free(p);
    }
    else
    {
        l->next = p->next;
        // free(p);
    }
}

void concat(int destIndex, int fromIndex)
{
    if(isEmpty(fromIndex))
        return;
    end[destIndex]->next = head[fromIndex]->next;
    end[destIndex] = end[fromIndex];
    head[fromIndex]->next = NULL;
    end[fromIndex] = head[fromIndex];
}

void outPut(int index)
{
    table *p = head[index];
    if (isEmpty(index))
        printf("Done");
    else
        while (p != end[index])
        {
            p = p->next;
            printf("%s ", p->value);
        }
    printf("\n");
}

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}