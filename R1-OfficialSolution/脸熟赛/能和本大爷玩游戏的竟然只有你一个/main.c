#include <stdio.h>
#include <string.h>

char *my[10000] = {0};
int myHead = 0, myTail = 0, wifeHead = 0, wifeTail = 0;
char *wife[10000] = {0};
char *table[100] = {0};
int tableTop = 0;
char box[100][10] = {0};
char ans[10000][200] = {0};
int player = 1;
int finishStep = 99999;

void giveCard(char *card)
{
    if (player == 0)
    { // 小z
        my[myTail] = card;
        myTail++;
    }
    else
    {
        wife[wifeTail] = card;
        wifeTail++;
    }
}

int existSame()
{
    char curr = table[tableTop - 1][1]; // 当前花色
    int i;
    for (i = 0; i < tableTop - 1; ++i)
    {
        if (table[i][1] == curr)
        {
            return i;
        }
    }
    return -1;
}

int oneStep()
{
    char *this;
    int sameCard;
    int finish;
    int j, giveNum;
    // 出牌
    if (player == 0)
    { // 小z
        table[tableTop] = my[myHead];
        myHead++;
    }
    else
    {
        table[tableTop] = wife[wifeHead];
        wifeHead++;
    }
    this = table[tableTop];
    tableTop++;

    // 判定
    // if (this[1] == 'J')
    // {
    //     // 全收走
    //     while (tableTop > 0)
    //     {
    //         tableTop--;
    //         giveCard(table[tableTop]);
    //     }
    // }
    // else 
    if (strcmp("JOKER", this) == 0 || strcmp("joker", this) == 0)
    {
        giveNum = strcmp("JOKER", this) == 0 ? 5 : 3;
        for (j = 0; j < giveNum; ++j)
        {
            if (player == 0)
            {
                my[myTail] = wife[wifeHead];
                myTail++, wifeHead++;
                if (wifeTail == wifeHead)
                {
                    return 1;
                }
            }
            else
            {
                wife[wifeTail] = my[myHead];
                myHead++, wifeTail++;
                if (myHead == myTail)
                {
                    return 1;
                }
            }
        }
    }
    else if ((sameCard = existSame()) >= 0)
    {
        while (tableTop > sameCard)
        {
            tableTop--;
            giveCard(table[tableTop]);
        }
    }

    // 输出答案
    if (myHead == myTail || wifeTail == wifeHead)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 模拟全部的步骤
void simuAll()
{
    int step;
    int printMove = 0;
    int i;
    for (step = 1; step <= 10000; ++step)
    {
        player = !player;
        if (oneStep())
        {
            finishStep = step;
            if (myTail == myHead)
            {
                sprintf(ans[step], "Kurisuwin\n");
            }
            else
            {
                sprintf(ans[step], "Zwin\n");
            }
            return;
        }
        else
        {
            printMove = 0;
            for (i = myHead; i <= myTail - 2; ++i)
            {
                printMove += sprintf(ans[step] + printMove, "%s ", my[i]);
            }
            printMove += sprintf(ans[step] + printMove, "%s\n", my[myTail - 1]);
            for (i = wifeHead; i <= wifeTail - 2; ++i)
            {
                printMove += sprintf(ans[step] + printMove, "%s ", wife[i]);
            }
            sprintf(ans[step] + printMove, "%s\n", wife[wifeTail - 1]);
        }

        // printf("%d\n",step);
    }
}

int main()
{
    int i, Q, K;
    for (i = 0; i < 27; ++i)
    {
        scanf("%s", box[i]);
        my[i] = (char *)(box + i);
    }
    myTail = 27;
    for (i = 0; i < 27; ++i)
    {
        scanf("%s", box[i + 27]);
        wife[i] = (char *)(box + i + 27);
    }
    wifeTail = 27;
    scanf("%d", &Q);
    simuAll();
    for (i = 0; i < Q; ++i)
    {
        scanf("%d", &K);
        if (K >= finishStep)
        {
            printf(ans[finishStep]);
        }
        else
        {
            printf(ans[K]);
        }
    }
}