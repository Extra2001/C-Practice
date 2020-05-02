#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char time[20];
char aMess[105];
char select1[] = "buaaycm";
int forbid[] = {23333, 233333, 66666, 666666, 114514};

typedef struct hh
{
    int time;
    int type;
    int length;
    char *message;
} mess;

mess *arr[105];
mess *constructor(char[], char[]);
int getTime(char time[]);

int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in4.txt", "r", stdin);
    int count = 0;
    while (gets(time) != NULL)
    {
        while (isspace(time[strlen(time) - 1]))
            time[strlen(time) - 1] = '\0';
        if (strlen(time) == 0)
            continue;
        gets(aMess);
        int isSelect = 1;
        //判断是否为查询命令
        if (strlen(aMess) == 8)
        {
            for (int i = 0; i < 7; i++)
            {
                if (aMess[i] != select1[i])
                {
                    isSelect = 0;
                    break;
                }
            }
        }
        else
            isSelect = 0;
        mess *tmp;
        if (isSelect)
        {
            //查询命令
            printf("yaiyai!\n");
            int nowTime = getTime(time);
            int c = 0;
            for (int i = count - 1; i >= 0; i--)
            {
                if (c >= 10)
                    break;
                if (nowTime - arr[i]->time <= 180)
                {
                    if (arr[i]->length == 5)
                        printf("%ds:[%05d] %s\n", nowTime - arr[i]->time, arr[i]->type, arr[i]->message);
                    else
                        printf("%ds:[%06d] %s\n", nowTime - arr[i]->time, arr[i]->type, arr[i]->message);
                    c++;
                }
            }
            if (c == 0)
                printf("buaamyc\n");
        }
        else if ((tmp = constructor(time, aMess)) != NULL)
            arr[count++] = tmp;
    }
}

mess *constructor(char time[], char message[])
{
    int count = 0;
    int l = 0, r = 0;
    int type;
    int typecount = 0;
    int length = 0;
    for (int i = 0; i <= strlen(message); i++)
    {
        if (message[i] >= '0' && message[i] <= '9')
        {
            if (count == 0)
            {
                l = i;
            }
            count++;
        }
        else
        {
            r = i - 1;
            char tmp[7];
            if (count == 5 || count == 6)
            {
                int j;
                for (j = 0; j < r - l + 1; j++)
                {
                    tmp[j] = message[l + j];
                }
                tmp[j] = '\0';
                int tmpi = atoi(tmp);
                int flag = 1;
                for (int k = 0; k < 5; k++)
                    if (tmpi == forbid[k])
                    {
                        flag = 0;
                        break;
                    }
                if (flag)
                {
                    type = atoi(tmp);
                    typecount++;
                    length = r - l + 1;
                    break;
                }
            }
            count = 0;
        }
    }
    if (typecount == 0)
    {
        return NULL;
    }
    mess *ret = (mess *)malloc(sizeof(mess));
    char *nm = (char *)malloc(sizeof(char) * 105);
    strcpy(nm, message);
    ret->type = type;
    ret->time = getTime(time);
    ret->length = length;
    ret->message = nm;
    return ret;
}

int getTime(char time[])
{
    int h, m, s;
    sscanf(time, "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}