# `A` 字符串库函数测试

## 题目描述

本题给出若干字符串操作，要求按照字符串操作执行。

## 输入

第一行为一个字符串A，长度不超过50。

第二行为一个正整数n。

接下来n行，进行多种操作。

修改操作：

第一种: strcpy s。表示向字符串A拷贝字符串s，s覆盖掉A。

第二种: strcat s。表示向字符串A末尾拼接字符串s，数据已经保证拼接后A总长度仍然不超过50。

询问操作：

第一种: strlen 询问当前字符串A的长度。

第二种: strstr s 询问字符串s在字符串A中出现的位置。比如，abc在abcdef中出现的位置是0。如果查找不到，答案是NULL。

这里保证所有修改和询问的字符串s不包含任何空白字符。

## 输出

 对于每个询问，输出询问的结果。所有操作结束后输出字符串A。

## 输入样例

    abcdef
    8
    strlen
    strcat GHI
    strstr abc
    strstr fG
    strcpy xyz
    strlen
    strstr abc
    strcat abc

## 输出样例

    6
    0
    5
    3
    NULL
    xyzabc

## 题目原型

编号321 [microhhh的字符串综合训练1](https://accoding.cn/problem/321/index)。原题是多组数据。这里只有单组数据。

_Author：李淳一_

# `B` 格雷编码

<div class="markdown-body ng-binding" ng-bind-html="Contest.data.problems[order].description | marked">

## 题目描述

姜老师`jlx`在数电课上介绍了卡诺图化简和格雷编码.这一编码方式的基本的特点就是

任意两个相邻的代码只有一位二进制数不同.

给你两个整数n m 保证n,m在[0,255] 

输出[n,m]的所有整数的8位二进制值和8位格雷编码

## 输入

两个整数n m,保证 0 &lt;= n &lt; m &lt;= 255

## 输出

共$m-n+1$行 每行为一个数$i$ $i$的二进制 $i$的格雷编码(见样例)

## 输入样例

    0 15

## 输出样例

    0 00000000 00000000
    1 00000001 00000001
    2 00000010 00000011
    3 00000011 00000010
    4 00000100 00000110
    5 00000101 00000111
    6 00000110 00000101
    7 00000111 00000100
    8 00001000 00001100
    9 00001001 00001101
    10 00001010 00001111
    11 00001011 00001110
    12 00001100 00001010
    13 00001101 00001011
    14 00001110 00001001
    15 00001111 00001000

## HINT

下面的函数可以生成格雷编码
`
int D2G(int x)
{
    return x^(x&gt;&gt;1);
}
`

 _author:cbj_

# `C` 小迷弟搞偷袭

<div class="markdown-body ng-binding" ng-bind-html="Contest.data.problems[order].description | marked">

## 题目描述

小迷弟的口头禅是“我大哥（指$lnx$）天下无敌”，但是小迷弟本身却菜得一批，只会搞偷袭，他的武力值属实低下，只能偷袭武力值小于他的弱鸡。但他又说自己从来不斩无名之辈，于是他就想知道`自己能斩的弱鸡当中武力值最高的是多少`。但小迷弟的实力飘忽不定，不同形态下的小迷弟武力值不一样，你需要帮他找到`每一种形态`下能斩的最强弱鸡的武力值。

即对于$m$个数中的每一个数，在$n$个数中找到小于这个数的最大数，若不存在输出`too weak`。

## 输入

第一个数为弱鸡总数$n$。

第二个数是小迷弟形态数$m$。

接下来$n$个数，第$i$个数代表第$i$个弱鸡的武力值。

接下来$m$个数，第$i$个数表示小迷弟在第$i$种形态下的武力值。

## 输出

输出$m$行$m$个数，第$i$个数代表第$i$种形态下能斩的最强弱鸡的武力值。如果小迷弟谁也打不过输出"too weak"(引号不输出)

## 输入样例

    3 3
    2 1 4
    3 2 1

## 输出样例

    2
    1
    too weak

## 数据范围

$1≤n,m≤100,000$

所有人武力值均在`int`范围内。

如果想通过本题的话，你需要回想一下之前学的二分查找。

_AUTHOR:今天是不讲武德偷袭老同志的小迷弟_

# `D` 李白打酒

## 题目背景

民间广为流传这么一个问题：李白街上走，提壶去打酒；遇店加一倍，见花喝一斗，三遇店和花，喝光壶中酒。试问酒壶中，原有多少酒？

这是一道简单数学应用题，现有一道类似的编程题。

## 题目介绍

李白人称“酒仙”，以豪饮而闻名天下。这天李白提着一壶新的容量为 `v` 斗的酒长途旅行，旅途中每一天会有如下奇遇之一：
- 遇店：来到补给处，李白可以选择一壶酒**加一倍**量，但不能超过酒壶的容量，如酒壶是空的或是满的均无法加酒。
- 遇花：李白诗性大发，选择一壶酒**畅饮一斗**。
- 遇友人：有朋自远方来，朋友会送李白**一壶新的容量为 `v` 斗的酒**。

每次要加酒的时候，李白会选择所有壶中剩余酒量**最少**（不包含 $0$ 斗）的一壶；

每次要喝酒的时候，李白会选择所有壶中剩余酒量**最多**的一壶。

请你输出每一天过后李白手中剩余多少斗酒。（若不能加酒也要照常输出）

## 输入格式

第一行一个正整数 `v` ，表示酒壶容量。

第二行一个正整数 `n` ，表示旅途一共有多少天。

第三行 $n$ 个以一个空格分隔的正整数 `op` ，表示旅途中每一天的奇遇。其中 $op\in\{1,2,3\}$ ，分别表示“遇店、遇花、遇友人”。

## 输出格式

旅途每经过一天输出一行，对于第 $i$ 天旅途 $(1\leq i\leq n)$，先输出`Day i: `，接着，

若旅途当天**遇花而没有酒可喝**，输出字符串`Such beautiful flowers, what a pity!`

否则输出一个非负整数，表示这天过后李白**剩余多少斗酒**。

## 输入样例

```
2
9
3 1 2 1 2 2 2 2 2
```

## 输出样例

```
Day 1: 4
Day 2: 4
Day 3: 3
Day 4: 4
Day 5: 3
Day 6: 2
Day 7: 1
Day 8: 0
Day 9: Such beautiful flowers, what a pity!
```

## 样例解释

旅途的第一天，李白遇友人，于是第一天过后有 $(2+2)$ 斗酒；第二天遇店，由于酒壶都是满的故无法加酒；第三天遇花，畅饮一斗酒，因此这天过后剩余 $(1+2)$ 斗酒；第四天遇店，给剩余 $1$ 斗酒的酒
壶加一倍量，这天过后剩余 $(2+2)$ 斗酒；接下来 $5$ 天都遇花，旅行第八天后剩余 $0$ 斗酒，第九天遇花时无酒可喝，于是发出感慨。

## 数据范围

$v$ 是 $int$ 范围内的正整数，$1≤n≤5×10^4$，数据保证正常情况下 $O(n^2)$ 可以通过。

本题纯属瞎编，数据不一定属实，请不必深究。

## HINT

如果WA了最后两个点，请考虑数据范围。

_Author: WQH_

# `E` djj的奇怪数列

## 题目描述

定义一个这样的奇怪数列，数列中的每个数都满足如下规则：
- 最多包含 $1,2,3,4,5$ 这五个数字中的任意多个；
- 开头可以是 $1,2,3,4,5$ 中任意一个；
- 数字 $1$ 后面只能跟 $3$ 或 $5$ ；
- 数字 $2$ 后面只能跟 $3$ 或 $4$ ；
- 数字 $3$ 后面只能跟 $1$ 或 $4$ ；
- 数字 $4$ 后面只能跟 $5$ ；
- 数字 $5$ 后面能跟 $1,2,3,4,5$ ；

将满足上述条件的数列中的数从小到大排列，如下所示：

$$

1,2,3,4,5,13,15,23,24,31,\cdots

$$

输入一个正整数 $n$ ，请输出这个数列中能被 $n$ 整除的最小正整数。

## 输入格式

输入为一行，一个正整数 $n$ ；

## 输入格式

输出一个数，为这个数列中能被 $n$ 整数的最小数 $m$ ；

## 输入样例

```
12
```

## 输出样例

```
24
```

## 数据范围

$1\leq n \leq 10^5$ ；

保证输出结果在 `int` 范围内；

保证数列中存在可以被 $n$ 整除的数；

保证所求数在数列中的位置不超过 $10^5$ 。        

## HINT

队列

### ps

*题面来源于2020级理科-大学计算机基础*

*AUTHOR：cbd*

# `F` 补码相反数


## 题目介绍

二进制补码是当今最常用的系统，我们以 $1$ 字节（也就是 $8$ 个二进制位）来说明这种方法；**（如果你对二进制补码很熟悉了，请直接看本段最后一句话）**

二进制补码用 $1$ 字节的后 $7$ 位表示 $0 ～1 27$ ，高阶位设置为 $0$ ；如果高阶位是 $1$，表示的值是负。关于如何确定一个负值，我们用一个 $9$ 位组合 $100000000$（ $256$ 的二进制形式）减去这个负数的位组合，结果是该负值的量；

例如，假设一个负值的位组合是 $10000000$ ，作为一个无符号字节，该组合表示 $128$ ；作为一个有符号值，该组合表示负值（高阶位是 $1$ ），而且值是 $100000000-10000000$ ，即 $10000000（128）$ 。因此，该数是 $-128$ 。类似的， $10000001$ 是 $-127$  ， $11111111$ 是 $-1$ 。该方法可以表示 $-128 ～ 127$范围内的数。

现在我们给出一个补码表示的二进制数（最高位为符号位），求他的相反数。

## 输入格式

多组数据输入，数组组数不超过 $100$ 组，以文件结束符`EOF`结尾；

每组数据一行，为只包含`0`和`1`的字符串，长度为 $w$ ，表示一个 $w$ 位的二进制补码数，首位是符号位 $（2 \leq w \leq 10^5）$。

## 输出格式

每组数据输出一行；

如果输入的二进制补码数的相反数可以用 $w$ 位二进制补码表示出来，则输出一行字符串，表示输入的二进制补码数的相反数。要求不省略前导 $0$ ，即输出的字符串长度和输入一致；

如果不能，请输出 `Overflow!!`

## 输入样例

```
11111111
10000000
10000001
101001000101
0001
```

## 输出样例

```
00000001
Overflow!!
01111111
010110111011
1111
```

## HINT1

可以发现，如果 $x$ 是一个二进制补码数， $～x$ 是 $x$ 按位取非的结果，那么 $x+～x=-1$ ，即 $-x=～x+1$   
就是说将 $x$ 的每一位取反再加 $1$，就得到了二进制补码数 $x$ 的相反数。

## HINT2

参考以下代码实现对字符串的简单操作

```cpp
#include <stdio.h>
#include <string.h> //字符串处理函数的头文件
int main()
{
    int len,i;

    char str[100];
    scanf("%s",str);//读取一串二进制数

    len=strlen(str);//获取字符串str的长度
    for(i=0;i<len;i++)
    {
        char ch=str[i];//获取字符串的每一位字符
        //code
    }


    /*
    例如：输入是00000001;
    则str="00000001";
    len=8;

    str[0]='0',str[7]='1';
    注意是字符'0'，而不是数字0
    */

    return 0;
}
```

参考自**E2-2019级航类第2次正式上机- J** *（杜晨鸿、陈高翔）*

*AUTHOR：Bodan Chen*


# `G` 李白打酒2.0


## 题目介绍

李白爱酒尽人皆知，这天李白提着一壶新的容量为 $v$ 斗的酒长途旅行，旅途中每一天会有如下奇遇之一：
- 遇店：来到补给处，李白可以给自己的酒壶**加一倍量**，但不能超过酒壶的容量，如酒壶是空的或是满的均无法加酒。
- 遇花：李白诗性大发，**畅饮一斗**酒。

这次的旅行是孤独的，即无法“遇友人”，因此李白只有手里的一壶酒。

在这次旅途中，李白一共遇店 $n$ 次，遇花 $m$ 次，已知最后一次遇到的是花，他正好把酒喝光了。 

请你输出李白遇店遇花的所有可能次序有多少种，所有的排列必须满足**最后遇到花，且恰好把酒喝完**。

## 输入格式

输入共一行，包含三个正整数 $n,\ m,\ v$，其含义如题目介绍所述，三者间分别以一个空格分隔。

## 输出格式

输出一行一个正整数，表示遇店遇花所有可能次序的种数。

## 输入样例

```
2 9 5
```

## 输出样例

```
4
```

## 样例解释

样例的四种可能次序分别为：

```
花、花、店、花、花、店、花、花、花、花、花；
花、花、店、花、花、花、店、花、花、花、花；
花、花、花、店、花、店、花、花、花、花、花；
花、花、花、店、花、花、店、花、花、花、花；
```

## 数据范围

$1\leq n\leq 6$，$1\leq m\leq 50$，$1\leq v\leq 18$

*Author: WQH*


# `H` 动态链表操作


## 题目介绍

之前我们已经学习过单向动态链表的构建了！现在我们再继续练习一些动态链表的操作。

今天我们要练习的操作是：插入、删除和移动。

现在你手上有两条，每个节点包含一个字符串的链表`a`和`b`。为方便叙述，规定其中节点的索引（序号）从`0`开始，即第一个节点的索引为`0`。
- **插入**：在索引$i$处插入一个节点，插入前索引$i$及以后的节点向后移动。
- **删除**：删除索引$i$处的一个节点。
- **移动**：将链表`a`或`b`的从索引$i$开始的节点移动到另一张链表的尾部。

## 输入格式

第一行，3个正整数`n、m、k`，分别代表`a`、`b`链表的初始节点个数，以及操作的条数。

接下来`n`行，每行一个无空格的字符串，代表`a`链表中从索引$0$开始每个节点的数据。

接下来`m`行，每行一个无空格的字符串，代表`b`链表中从索引$0$开始每个节点的数据。

接下来`k`行，每行为一条操作，**一般格式**如下：

第一个数字，仅为`1、2、3`，分别代表插入、删除、移动。

第二个字符`t`，仅为`a`或`b`，代表要操作的链表。

第三个数字`i`，为要操作的节点索引。

对于**每种操作的具体格式**如下：
- **插入**：`1 t i data`<ul><li>向链表`t`中索引为`i`处插入一个节点，数据为`data`。
- 删除链表`t`中索引为`i`的节点。
- 将链表`t`中从索引为`i`起的节点移动至另一张链表。

## 输出格式

先后输出经过$k$次操作后，链表`a`和`b`中的数据，每行一个字符串。

链表`a`和`b`的输出数据之间加一行**空行**。

若该链表为空，请输出：`Empty!`

## 输入样例

```
3 2 3
akufegewfhu
asdkfhiweufewff
jiejwfi
aeifhfew
wifeojo21e
1 b 1 saldj
2 a 0
3 b 0
```

## 输出样例

```
asdkfhiweufewff
jiejwfi
aeifhfew
saldj
wifeojo21e

Empty!
```

## 数据范围

所有要保存的字符串都无空格，因此可以放心使用`scanf("%s")`读取。

字符串长度不超过$30$。

假如链表`a`当前的长度为$n$，那么其中包含索引为$0$到$n-1$的节点。此时，输入数据保证：
- 对于插入操作，索引范围为$[0, n]$
- 对于删除和移动操作，索引范围为$[0, n-1]$

无需关心$n、m、k$的大小，保证内存空间足够。

## HINTS

字符串的复制可不能直接赋值哦。

*Author: Xutian Jing*


# `I` 大美丽和大凶残


## 题目描述

助教LCY在一片水域钓上了各种各样的鱼。神奇的是，这些鱼生来带有一个整数编号，并且全是奇数。奇数天然可以分成两类：除以4余1和除以4余3，也可以分为两类：正数鱼和负数鱼。

*Notice：-1除以4余3，这可能与编程中的取模运算有些差异。你可以选择改写模函数，当模一个负数的时候变为模它的绝对值，当模的结果为负的时候，将结果加一个除数的绝对值转为正数。*

鱼也是社群动物，一条鱼在另一条鱼眼中会有不同的评判指标。一条鱼在另一条鱼看来，可能是美丽的，可能是凶残的，也可能什么都不是。

定义相同关系：关系与自身相同。

定义相反关系：美丽与凶残是相反关系；什么都不是和什么都不是是相反关系。

关于一条鱼在另一条鱼看来究竟是什么，有以下规则：

初始规则：

编号1在任何鱼看来都是美丽的，任何鱼在编号1看来都是美丽的。

编号-1在除以4余1型鱼看来是美丽的，在除以4余3型鱼看来是凶残的。

正数鱼在编号-1是美丽的，负数鱼在编号-1看来是凶残的。

如果m与n都不是1或-1，并且绝对值相等，那么m在n看来、n在m看来，什么都不是。

取模规则：

当n是正数鱼，m%n和m%n-abs(n)有一个是奇数，记为r。此时m在n看来与r在n看来的关系相同。

当n是负数鱼，m%n和m%n-abs(n)有一个是奇数，记为r。如果m和r正负性相同，m在n看来与r在n看来的关系相同；如果m和r正负性相反，m在n看来与r在n看来的关系相反。

换位规则：

当m和n至少有一个是正数鱼，并且至少有一个是除以4余1型鱼的时候，或者m和n都是负数鱼，并且都是除以4余3型鱼的时候，m在n看来，与n在m看来的关系相同。

当m和n至少有一个是正数鱼，并且都是除以4余3型鱼的时候，或者m和n都是负数鱼，并且至少有一个是除以4余1型鱼的时候，m在n看来，与n在m看来的关系相反。

助教LCY希望你交替使用取模规则和换位规则，每次都用初始规则特判是否退出，按照绝对值变小的原理，最终完成递归程序设计。

## 输入

本题为**不定组输入数据，请以`EOF`为结束符号。**

每组数据为一行两个整数（奇数）m和n。

## 输出

对于每组数据，输出一行字符串，具体如下：

如果m在n看来是美丽的，输出“Great beauty!”。

如果m在n看来是凶残的，输出“Great ferocity!”。

如果m在n看来什么都不是，输出“Nonsense.”。

## 输入样例

```
3 5
415 411
```

## 输出样例

```
Great ferocity!
Great beauty!
```

## Hint

*仿照最大公约数的递归程序设计*

由于模数是n的2倍，考虑绝对最小余数。即通过递归的设计，希望m和n的绝对值严格递减，直到递归到1或-1，或者相等为止。

*不需要知道的题目背景：Quadric Residue Symbol*

p.s. 准确的说，本题求的是弱化版的 "Kronecker Symbol",正经做的话需要"Legendre symbol"的背景知识，可以尝试结合大质因数分解，以及 [Kronecker符号介绍](https://mathworld.wolfram.com/KroneckerSymbol.html) , [Legendre符号介绍](https://mathworld.wolfram.com/LegendreSymbol.html), [Jacobi符号介绍](https://mathworld.wolfram.com/JacobiSymbol.html) ,将本题范围提升至 $n,m\in [-10^{18},10^{18}]$ 再做一遍。

*Author：李淳一*


# `J` 蒙达鲁克硫斯伯古比奇巴勒城的名册


## 题目背景

`蒙达鲁克硫斯伯古比奇巴勒城`住着很多居民，他们的名字都很长，比如亲王`达拉崩吧斑得贝迪卜多比鲁翁`、公主`米娅莫拉苏娜丹妮谢莉红`和皇孙`王浩然`。

现给出每个人的年龄和名字，请你将他们按照年龄从小到大排列并输出(如果年龄相同，先输入的排在前面)。

## 输入格式

第一行一个整数`n`($1 \leq n \leq 200005$)表示总共有多少人和一个整数`m`($1 \leq n \leq 10$)表示有多少次查询。
接下来`n`行每行一个整数`a`($0 \leq a \leq 10000$)表示年龄和一个字符串`s`(仅由英文小写字母组成，$1 \leq len(s) \leq1000$)表示名字，用一个空格分开。
接下来`m`行每行一个整数,表示需要查询排序完成后第几个人的信息（从1开始数）。

## 输出格式

对于每次查询，输出一行，包含一个整数和一个字符串，用空格分开，表示排序后该位置的人的年龄和名字。

## 输入样例

```
3 2
2 aaa
1 bbb
2 ccc
1
3
```

## 输出样例

```
1 bbb
2 ccc
```

## HINT

如果直接`qsort`排序不行的话，为何不试试对下标/二维指针的排序呢？

*AUTHOR:dch*


# `K` 小迷弟的灵光三现


## 题目描述

`难题预警`

小迷弟只有小聪明？不可能，小迷弟这次大聪明！他这次自认为已经彻底学会了异或的高端操作。

碰巧此时$lnx$又来问小迷弟问题了（为什么总为难我胖虎！）：

给定一个长度为$n$的非负整数数列 $a_1,a_2,...,a_n$ 和一个非负整数 $k$ ，**lnx**问**小迷弟** $m$ 个问题，每个问题只包含两个数 $L,R$，**小迷弟**需要答出从 $L$ 到 $R$ 中有多少种不同的方案 $l,r$ 使得$a_l\oplus a_{l+1}\oplus...\oplus a_r=k$且有$L≤l≤r≤R$，**小迷弟**需要在$0.5$秒的时间内回答出所有的问题。

尽管时间很紧，小迷弟灵光三现反手打开`Dev-C++`直接秒杀了**lnx**的所有问题。别夸别夸，现在轮到你了，小迷弟比较宽容，你在$1s$内答出来就可以了~

## 输入

第一行是$3$个整数 $n,m,k$。

第二行为空格分开的 $n$ 个整数,即 $a_1,a_2,...,a_n$

接下来$m$行，每行两个整数$L,R$表示一次查询。

## 输出

输出$m$行，每行一个整数，表示区间$L，R$内的方案数，如题意所示。

## 输入样例

```
5 2 1
1 2 3 2 1
1 3
1 4
```

## 输出样例

```
2
3
```

## 样例解释

第一组询问：$1$自己作为一组答案，$2$异或$3$也是$1$，故答案为$2$

第二组询问：在第一组询问的基础上，加上了后面的$2$和$3$异或，所以是$3$

## 数据范围

对于$100$%的数据，$1≤n,m≤10^5$，$0≤k,a_i≤10^5$，$1≤L≤R≤n$

## HINT

本题是为了提前让大家适应期末考试压轴题的难度，如果一定想做对，小迷弟提供了[网站资源](https://baijiahao.baidu.com/s?id=1611364100257622493&amp;wfr=spider&amp;for=pc)给大家学习。

*AUTHOR：今天是出离谱题的小迷弟*


# `L` 简单的函数求和



## 题目描述

C语言程序设计接近尾声了，至此即将完结撒花之际，非常感谢大家对我们这一学期工作的支持与理解！

无论中途遇到了多少的艰难险阻，点灯熬油修了多少的bug，有多少百思不得其解的问题，都走到了现在。对于一直坚持下来的大家，开花学长心里是十分敬佩的，大家都是好样的！

在大二后续的课程当中，可能也会出现付出了很多很多的努力，但是短时间看不到结果，或者达不到自己的预期，这种令人绝望的情形（开花学长就是这么一路被别人虐过来的）。但是希望大家，无论何时，依旧能够直面最真实的自己，最终真的能够学得一些东西，获得一些进步。

到了最后的最后，开花学长也给大家留下了一个简单的函数，作为留念。

这个函数是 $f(x)$ 。**虽然不知道他的具体值，但是他依旧留下了一些蛛丝马迹。**

可以知道的等式为：


$$

\sum_{d|x}f(d)=x^3+3x^2+x \quad (d>0)

$$


其中，$d|x$ 的意思是，$d$ 可以整除 $x$， $d$ 是 $x$ 的因子。 那么上述等式的意思就是，对于 $x$ 的所有因子 $d$ (包括 $x$ 自己) ，他们的函数值求和为 $x^3+3x^2+x$。

以 $x = 4$ 为例，就有 $f(1)+f(2)+f(4)=4^3+3\times 4^2+4=116$

以 $x=6$ 为例，就有 $f(1)+f(2)+f(3)+f(6)=6^3+3\times 6^2+6=330$

针对简单的函数，我们要做的就是简单的函数求和，求解为 $F(n)$，其中


$$

F(n)=\sum_{i=1}^n f(i)

$$


由于这个数字可能大的离谱，所以我们只需要输出他对质数 $1,000,000,007$ 取模的结果即可。

## 输入

本题的每一个测试点**均为多组数据输入，请采用`EOF`判断结尾。**

每组数据 $1$ 行，包含一个正整数 $n$ 。

## 输出

对于每组数据，输出一行，为 $F(n)$ 对 $1,000,000,007$ 取模的值。

## 输入样例

```
1
2
3
4
```

## 输出样例

```
5
22
74
168
```

## 数据范围

对于所有的数据，保证每一个 $n$ 均为合法的**正整数**形式。

对于测试点 $01$,保证 $n \le 10^2$, 数据组数不大于 $100$。

对于测试点 $02$,保证 $n \le 10^4$, 数据组数不大于 $10000$。

对于测试点 $03$,保证 $n\le 10^6$, 数据组数不大于 $10000$。

对于测试点 $04,05,06, 07$,保证 $n \le 10^{9}$, 数据组数不大于 $30$。

## HINT

如果没有思路的话，可以查阅一下欧拉函数 $\phi(x)$ 的相关资料与性质，以及如何求欧拉函数之和。

最后感谢大家对我们一学期以来工作的大力支持！在此祝大家期末考试取得让自己满意的成绩！

*Author: 计组OO两开花*
