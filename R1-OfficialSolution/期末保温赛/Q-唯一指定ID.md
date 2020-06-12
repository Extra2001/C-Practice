  `Q` 唯一指定ID
  ====
  ----
  整体步骤为先检查身份证号码是否合格，然后计算出生到现在的天数。

  检查身份证号合格应依次检查：号码长度，前17位均为数字，校验码计算正确，生日正确。

  其中检查生日正确的步骤又分为：月份数正确（1到12之间），日期数正确（1到本月最后一天，注意闰年！），以及出生日期不得晚于`2019/4/2`

  计算从出生日到今天的天数可以采用如下方法：

  先计算出生年的1月1日到本年1月1日的天数：`s1=365*(y2-y1)+k`，其中k是这其中闰年的数量（包括出生年，不包括当前年）

  再分别计算出生日期和今天是当年的第几天（此处分别记为`d1,d2`）

  则`s1+d2-d1`即为本题答案。
  ```c
  #include <stdio.h>
#include <string.h>
#include <ctype.h>
char id[19];
int w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char ck[] = "10X98765432";//mod 11
int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int YY,MM,DD;
int isleap(int y)
{
    if (y % 4 == 0 && y % 100 != 0)return 1;
    else if (y % 400 == 0)return 1;
    else return 0;
}
int islegal()
{
    int i,l = strlen(id), s = 0;
    int y,m,d;
    //只要有一项检查不过，直接return 0;
    /*----ID Code Check Begin----*/
    if (l != 18)return 0;
    //Length is 18;
    for (i = 0;i<17;i++)
    {
        //Every digit must be a number except the Check Code
        if (id[i] >= '0' && id[i] <= '9')
        {
            s += (id[i] - '0') * w[i];
        }
        else return 0;
    }
    //All digits are numbers;
    if (toupper(id[17]) != ck[s % 11])return 0;
    //Check Code is correct;
    /*---ID Code is Legal---*/

    /*----Birthday Check Begin----*/
    //Extract the year, month, day;
    y = 1000 * (id[6] - '0') + 100 * (id[7] - '0') 
      + 10 * (id[8] - '0') + (id[9] - '0');
    m = 10 * (id[10] - '0') + (id[11] - '0');
    d = 10 * (id[12] - '0') + (id[13] - '0');

    if (isleap(y))month[2] = 29;//leap year;
    if (y < 2019)
    {
        if (m > 12 || m <= 0)return 0;
        //month not in [1,12] is illegal, such as 2018/0/1 or 2017/13/12;
        if (d > month[m] || d <= 0)return 0;
        //day is out of this month, such as Jan.0 or Feb.30
    }
    else
    {
        //Birthday cannot be later than 2019/4/2
        if (m > 4 || m <= 0)return 0;
        if (m < 4 && (d > month[m] || d <= 0))return 0;
        if (m == 4 && (d > 2 || d <= 0))return 0;

    }
    /*---Birthday is legal---*/
    YY = y, MM = m, DD = d;
    //save the birthday to global varibles, in order to calculate the count of days

    return 1;//Passed all the checkpoints
}
int daysofyear(int y,int m,int d)
{
    //指定日期是该年中的第几天
    int r = 0,i;
    if (isleap(y))month[2] = 29;
    else month[2] = 28;
    for (i = 1;i<m;i++)r += month[i];
    r += d;
    return r;
}
int calc_delta_days(int y1,int m1,int d1,int y2,int m2,int d2)
{
    //计算y2年1月1日到y1年1月1日的差
    //再加上y2年daysofyear减去y1年的daysofyear
    int cnt_leap = 0, i;
    int dy,dd1,dd2;
    for (i = y1;i<y2;i++)
    {
        if (isleap(i))cnt_leap++;
    }
    dy = 365 * (y2 - y1) + cnt_leap;
    dd1 = daysofyear(y1,m1,d1);
    dd2 = daysofyear(y2,m2,d2);
    return dy + dd2 - dd1;
}
int main()
{
    scanf("%s",id);
    if (islegal())//判断身份证号是否有效
    {
        printf("%d\n",calc_delta_days(YY,MM,DD,2019,4,2));
        //计算他出生了多少天
    }
    else
    {
        printf("Chawuciren\n");
    }
    return 0;
}
  ```
  