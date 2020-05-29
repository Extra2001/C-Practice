#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    char buf[22];
    scanf("%s", buf);
    Init(buf);
    while (~scanf("%s", buf))
    {
        Insert(buf);
        if (count > n)
            Delete(0);
    }
    puts(head->value);
    // fclose(stdin);
}

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

int TrimEnd(char *base)
{
    while (isspace(base[strlen(base) - 1]))
        base[strlen(base) - 1] = '\0';
    return strlen(base);
}