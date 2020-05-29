#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//使用前请注意：本链表头部也包含数据。

typedef struct ta
{
    char value[22];
    struct ta *next;
} table;

table *head = NULL, *end = NULL;
int count = 0;

void Init(char *value);
void Delete(int index);
void Insert(char *value);
int TrimEnd(char *base);


void Init(char *value)
{
    head = (table *)malloc(sizeof(table));
    head->next = NULL;
    end = head;
    strcpy(end->value, value);
    count = 1;
}

void Insert(char *value)
{
    end->next = (table *)malloc(sizeof(table));
    end = end->next;
    strcpy(end->value, value);
    end->next = NULL;
    count++;
}

void Delete(int index)
{
    table *p = head, *l = NULL;
    for (int i = 0; i < index; i++)
    {
        l = p;
        p = p->next;
    }
    if (l == NULL)
    {
        head = head->next;
        free(p);
    }
    else
    {
        l->next = p->next;
        free(p);
    }
    count--;
}