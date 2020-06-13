#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN1(a) scanf("%d", &a);
#define IN2(a, b) scanf("%d%d", &a, &b);
#define IN3(a, b, c) scanf("%d%d%d", &a, &b, &c);

int TrimEndR(char *base);

typedef struct ta
{
    int value;
    struct ta *next;
} table;

table *head = NULL, *end = NULL;
int count = 0;

void Init()
{
    head = (table *)malloc(sizeof(table));
    head->next = NULL;
    end = head;
    count = 0;
}

void Insert(int value)
{
    end->next = (table *)malloc(sizeof(table));
    end = end->next;
    end->value = value;
    end->next = NULL;
    count++;
}

//index要保证大于0，因为head也算作一个节点但head不包含数据
void Delete(int index)
{
    table *p = head, *l = NULL;
    for (int i = 0; i < index; i++)
    {
        l = p;
        p = p->next;
    }
    if (p->next == NULL)
        end = l;
    l->next = p->next;
    free(p);
    count--;
}

void checkBeforeAdd(int value)
{
    int index = 1;
    for (table *p = head->next; p != NULL; p = p->next)
    {
        if (p->value != value)
        {
            Delete(index);
            return;
        }
        index++;
    }
    Insert(value);
}

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    Init();
    int cur;
    while (~scanf("%d", &cur))
    {
        checkBeforeAdd(cur);
    }
    printf("%d", head->next->value);
    // fclose(stdin);
}

int TrimEndR(char *base)
{
    while (base[strlen(base) - 1] == '\r')
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}