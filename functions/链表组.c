#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//使用前请注意：本链表头部不包含数据。

#define INF 1000005

typedef struct ta
{
    char value[20];
    struct ta *next;
} table;

table *head[INF], *end[INF];

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
        free(p);
    }
    else
    {
        l->next = p->next;
        free(p);
    }
}

void concat(int destIndex, int fromIndex)
{
    if (isEmpty(fromIndex))
        return;
    end[destIndex]->next = head[fromIndex]->next;
    end[destIndex] = end[fromIndex];
    head[fromIndex]->next = NULL;
    end[fromIndex] = head[fromIndex];
}