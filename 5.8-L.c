#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ColHHH
{
    // 1: 整数 2: 实数 3: 字符串 4: 日期
    char type;
    union AAA {
        int INT;
        double REAL;
        char STRING[105];
        int DATE;
    } data;
} Col;

typedef struct RowHHH
{
    char rowdata[10015];
    Col col[105];
} Row;

Row row[1015];
char props[105][105], types[105];
int propcount;
int cmpbuffer[105], asc[105], cmpcount = 0;

void ReadLine(int i);
void ReadProp();
int cmp(const void *a, const void *b);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    int r;
    scanf("%d%d", &r, &propcount);
    ReadProp();
    for (int i = 0; i < r; i++)
        ReadLine(i);
    char tmp[105];
    for (int j = 0; ~scanf("%s%d", tmp, &asc[j]); j++)
    {
        for (int i = 0; i < propcount; i++)
        {
            if (strcmp(tmp, props[i]) == 0)
            {
                cmpcount++;
                cmpbuffer[j] = i;
                break;
            }
        }
    }
    qsort(row, r, sizeof(row[0]), cmp);
    for (int i = 0; i < propcount; i++)
    {
        printf("%s ", props[i]);
    }
    printf("\n");
    for (int i = 0; i < r; i++)
    {
        puts(row[i].rowdata);
    }
    // fclose(stdin);
}

void ReadLine(int i)
{
    do
        gets(row[i].rowdata);
    while (strlen(row[i].rowdata) == 0);
    char *p = row[i].rowdata;
    char tmp[200];
    for (int j = 0; j < propcount; j++)
    {
        sscanf(p, "%s", tmp);
        row[i].col[j].type = types[j];
        if (types[j] == 1)
            sscanf(p, "%d", &(row[i].col[j].data.INT));
        else if (types[j] == 2)
            sscanf(p, "%lf", &(row[i].col[j].data.REAL));
        else if (types[j] == 3)
            sscanf(p, "%s", row[i].col[j].data.STRING);
        else if (types[j] == 4)
        {
            int y, m, d;
            sscanf(p, "%d-%d-%d", &y, &m, &d);
            char tm[10];
            sprintf(tm, "%04d%02d%02d", y, m, d);
            sscanf(tm, "%d", &(row[i].col[j].data.DATE));
        }
        if (j != propcount - 1)
            p += strlen(tmp) + 1;
    }
}

void ReadProp()
{
    for (int i = 0; i < propcount; i++)
    {
        scanf("%s", props[i]);
    }
    char tmp[10];
    for (int i = 0; i < propcount; i++)
    {
        scanf("%s", tmp);
        if (strcmp("INT", tmp) == 0)
            types[i] = 1;
        if (strcmp("REAL", tmp) == 0)
            types[i] = 2;
        if (strcmp("VARCHAR", tmp) == 0)
            types[i] = 3;
        if (strcmp("DATE", tmp) == 0)
            types[i] = 4;
    }
}

int cmp(const void *a, const void *b)
{
    for (int i = 0; i < cmpcount; i++)
    {
        Col f1 = ((Row *)a)->col[cmpbuffer[i]];
        Col f2 = ((Row *)b)->col[cmpbuffer[i]];
        if (f1.type == 1)
        {
            int cm = (f1.data.INT - f2.data.INT) * asc[i];
            if (cm == 0)
                continue;
            else
                return cm;
        }
        else if (f1.type == 2)
        {
            double cm = (f1.data.REAL - f2.data.REAL) * asc[i];
            if (fabs(cm) < 1e-5)
                continue;
            else
            {
                if (cm > 0)
                    return 1;
                else
                    return -1;
            }
        }
        else if (f1.type == 3)
        {
            int cm = strcmp(f1.data.STRING, f2.data.STRING) * asc[i];
            if (cm == 0)
                continue;
            else
                return cm;
        }
        else if (f1.type == 4)
        {
            int cm = (f1.data.DATE - f2.data.DATE) * asc[i];
            if (cm == 0)
                continue;
            else
                return cm;
        }
        else
            return 0;
    }
    return 0;
}