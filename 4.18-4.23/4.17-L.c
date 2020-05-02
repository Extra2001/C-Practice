#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char temp[10015];

struct number
{
    char num[10015];
    int length;
    int isNegative;
};
struct number *Constructor(char num[])
{
    char *p = num;
    int length = strlen(p), isNegative = 0;
    if (*p == '-')
    {
        isNegative = 1;
        p++;
        length--;
    }
    if (length == 1 && *p == '0')
        isNegative = 0;
    else
        while (*p == '0')
        {
            p++;
            length--;
            if (length == 1)
            {
                if (*p == '0')
                {
                    isNegative = 0;
                }
                break;
            }
        }
    struct number *ret = (struct number *)malloc(sizeof(struct number));
    ret->isNegative = isNegative;
    ret->length = length;
    strcpy(ret->num, p);
    return ret;
}
int Judge(struct number *num1, struct number *num2)
{
    if (num1->length > num2->length)
    {
        return 1;
    }
    else if (num1->length < num2->length)
    {
        return 2;
    }
    else
    {
        char *a = num1->num, *b = num2->num;
        int flag = 0;
        while (a != (num1->num + num1->length) && *a == *b)
        {
            a++;
            b++;
        }
        if (*a == *b && *a == '\0')
            return 0;
        else if (*a > *b)
            return 1;
        else
            return 2;
    }
}
struct number *Add(struct number *num1, struct number *num2)
{
    memset(temp, '0', sizeof(temp));
    int overflow, isoverflow = 0;
    if (num2->length < num1->length)
    {
        struct number *tmp = num1;
        num1 = num2;
        num2 = tmp;
        tmp = NULL;
    }
    temp[num2->length + 1] = '\0';
    int len = num2->length;
    int delta = num2->length - num1->length;
    for (int i = len - 1; i >= 0; i--)
    {
        if (i - delta >= 0)
        {
            if (isoverflow)
            {
                int sum = overflow + num1->num[i - delta] - 48 + num2->num[i] - 48;
                if (sum > 2)
                    overflow = sum / 3;
                else
                    isoverflow = 0;
                temp[i + 1] = sum % 3 + 48;
            }
            else
            {
                int sum = num1->num[i - delta] - 48 + num2->num[i] - 48;
                if (sum > 2)
                {
                    overflow = sum / 3;
                    isoverflow = 1;
                }
                temp[i + 1] = sum % 3 + 48;
            }
        }
        else
        {
            if (isoverflow)
            {
                int sum = overflow + num2->num[i] - 48;
                if (sum > 2)
                    overflow = sum / 3;
                else
                    isoverflow = 0;
                temp[i + 1] = sum % 3 + 48;
            }
            else
            {
                int sum = num2->num[i] - 48;
                if (sum > 2)
                {
                    overflow = sum / 3;
                    isoverflow = 1;
                }
                temp[i + 1] = sum % 3 + 48;
            }
        }
    }
    if (isoverflow)
    {
        int sum = overflow;
        if (sum > 2)
            overflow = sum / 3;
        else
            isoverflow = 0;
        temp[0] = sum % 3 + 48;
    }
    return Constructor(temp);
}
struct number *Subtract(struct number *num1, struct number *num2)
{
    memset(temp, '0', sizeof(temp));
    int a;
    if ((a = Judge(num1, num2)) == 0)
    {
        char a[] = "0";
        return Constructor(a);
    }
    else if (a == 2)
    {
        struct number *tmp = num1;
        num1 = num2;
        num2 = tmp;
        tmp = NULL;
    }
    int overflow = 1, isoverflow = 0;
    temp[num1->length + 1] = '\0';
    int len = num1->length;
    int delta = num1->length - num2->length;
    for (int i = len - 1; i >= 0; i--)
    {
        if (i - delta >= 0)
        {
            if (isoverflow)
            {
                int sum = num1->num[i] - num2->num[i - delta] - overflow;
                if (sum < 0)
                    sum += 3;
                else
                    isoverflow = 0;
                temp[i + 1] = sum + 48;
            }
            else
            {
                int sum = num1->num[i] - num2->num[i - delta];
                if (sum < 0)
                {
                    sum += 3;
                    isoverflow = 1;
                }
                temp[i + 1] = sum + 48;
            }
        }
        else
        {
            if (isoverflow)
            {
                int sum = num1->num[i] - 48 - overflow;
                if (sum < 0)
                    sum += 3;
                else
                    isoverflow = 0;
                temp[i + 1] = sum + 48;
            }
            else
            {
                int sum = num1->num[i] - 48;
                temp[i + 1] = sum + 48;
            }
        }
    }
    struct number *ret = Constructor(temp);
    if (num1->isNegative)
    {
        ret->isNegative = 1;
    }
    if (ret->length == 1 && ret->num[0] == '0')
    {
        ret->isNegative = 0;
    }
    return ret;
}
void Out(struct number *num)
{
    if (num->isNegative)
    {
        putchar('-');
    }
    puts(num->num);
    free(num);
}
int main()
{
    // freopen("C:\\Users\\Lenovo\\Projects\\C_for_code\\in.txt", "r", stdin);
    while (~scanf("%s", temp))
    {
        struct number *num1 = Constructor(temp);
        scanf("%s", temp);
        struct number *num2 = Constructor(temp);
        if (num1->isNegative == 0 && num2->isNegative == 0)
        {
            Out(Add(num1, num2));
        }
        else if (num1->isNegative && num2->isNegative)
        {
            struct number *out = Add(num1, num2);
            out->isNegative = 1;
            Out(out);
        }
        else
        {
            Out(Subtract(num1, num2));
        }
    }
    // fclose(stdin);
}