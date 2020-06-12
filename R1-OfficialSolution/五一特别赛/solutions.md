# A 复习位运算

核心代码：`(x << 16) | (x >> 16)`。注意读写 `unsigned int` 使用的是 `%u`。

# C 填报高考志愿

不妨假设我们有一个函数 `lower_bound`，可以找到单调不减数组 $a$ 中第一个满足 $a_i \geq x$ 的位置 $i$，则这个位置附近的几个数与 $x$ 之差的绝对值一定是最小的。由于要对每个 $b_i$ 都查询一次，因此查询过程应当尽可能地高效，为此我们可以采用二分。

下面给出 `lower_bound` 的一个实现，表示在 $a_L, a_{L+1}, \ldots, a_{R-1}$ 中查找第一个满足 $a_i \geq x$ 的位置 $i$。

```c
int lower_bound(int a[], int L, int R, int x){
	while(L < R){
		int M = (L + R) / 2;
		if(a[M] < x) L = M + 1;
		else R = M;
	}
	return L;
}
```

> 注意：整数的二分代码的坑比较多，如果你并没有真正理解二分，可能会在自己写的时候出现死循环。


# E jqe的数列

本题与“求阶乘·改”一题的解法相同，这里作为课外拓展介绍提示中在更大数据范围下的做法。

不妨令 $\vec v_n = [a_n, a_{n-1}, a_{n-2}, \sum _{i=1}^n a_i]$，$A$ 为如下的转移矩阵：

$$
A = 
\begin{bmatrix}
	1	&1	&0	&1 	\\
	1	&0	&1	&1	\\
	1	&0	&0	&1	\\
	0	&0	&0	&1	\\
\end{bmatrix}
$$

不难发现，$\vec v_{n+1} = \vec v_n A$，因此 $\vec v_{n} = \vec v_3 A^{n - 3}$，其中 $A^n$ 可以通过 [快速幂](https://oi-wiki.org/math/quick-pow/) 高效完成计算。



# F 爬爬爬

不妨设以 $i$ 为右端点时，最长能记下区间的左端点是 $pre$，则此时答案为 $i - pre + 1$。现在考虑 $i$ 变成 $i + 1$ 时，$pre$ 如何变化。

假如很不巧，$a_{i+1}$ 的字符在区间 $[pre, i]$ 中出现过，则 $pre$ 需要不断增加，直到 $a_{i+1}$ 不在区间 $[pre, i]$ 中出现过，此时的 $[pre', i+1]$ 就是我们新得到的区间。为了快速知道字符 `x` 是否在区间中出现过，可以维护一个 `vst[x]` 数组，当区间的两个端点移动时，对应修改端点的 `vst[x]` 值为 $0$ 或 $1$ 即可。

根据上面的过程不难发现，$pre$ 变量是一个从 $1$ 到 $n$ 单调变化的值，因此对每个 $i$ 而言，$pre$ 变化的过程均摊是 $1$，而不需要把 $pre$ 看做是一重循环。因此，该做法的时间开销是关于 $n$ 的一重循环，可以通过本题。


# G monotonicity

不妨设以 $i$ 为左端点时，最小满足条件的区间右端点是 $nxt$，则此时答案为 $nxt - i + 1$。现在考虑 $i$ 变成 $i + 1$ 时，$nxt$ 如何变化。

与 F 题类似，由于所有元素非负，因此 $i$ 变为 $i+1$ 时，区间元素和不可能增加，故为了让元素和 $\geq S$，右端点 $pre$ 可能需要向右移动，故也是从 $1$ 到 $n$ 单调变化的值。由上题可以同理得到该做法的时间开销是关于 $n$ 的一重循环，可以通过本题。



# H djj的异或序列

不妨令异或前缀和 $s_n = \bigoplus_{i=0}^n a_i$，其中 $\oplus$ 表示异或符号，$\bigoplus$ 表示连异或符号，则区间 $[l, r]$ 异或和为 $0$ 等价于 $s_r \oplus s_{l-1} = 0$，即 $s_{l-1}  = s_r$，因此我们只需要统计有多少对 $s_n$ 相同即可（一对相同异或和唯一对应了一个异或和为 $0$ 的区间）。

特殊地，我们规定 $a_0 = 0$。



# I 午间

将时间转化为“本周开始的某一分钟后”，题目变为多次区间加一个值，求最后区间单点最大值。这个问题是 [差分](https://oi-wiki.org/basic/prefix-sum/#_8) 和 [前缀和](https://oi-wiki.org/basic/prefix-sum/#_1) 的经典题目，可以参考上述链接。

# L 蟠桃大会

贪心。要点1:**最多**有m*n次机会选择盘子吃桃子。要点2:对于每一个不同编号的盘子，**最多**可以拿m个桃子吃。

# M 遥不可及的军训

我们不难算出来有多少个编号为 $i$ 的人，实际应该要到编号为 $j$ 的位置上，并画出下面的关系图。可以发现，最后的交换局面一定是这样的：

![](https://images.gitee.com/uploads/images/2020/0505/121652_8e90271d_6537196.png)


首先我们先考虑两两交换的情况，也就是把 $i$ 和 $j$ 之间的双向边都变成单向边。比如说，有 $a$ 个人要从 $1$ 到 $2$，有 $b$ 个人要从 $2$ 到 $1$，那最优的方法是选 $x = \min(a, b)$，通过交换 $x$ 次使得 $a$ 和 $b$ 的其中一个变为 $0$。

经过这样交换，要么所有人已经交换完了，要么只能是这种情况（或边的方向反过来）：

![](https://images.gitee.com/uploads/images/2020/0505/121652_921a5005_6537196.png)

因为一旦不是上述情况，就会有某个编号出现只进不出或只出不进的局面，而这是不可能的。这种情况下，每要让三个人位置正确，都需要两次交换。这样，所有人就都交换完毕了。


# N Serein的扫雷游戏

 遇到 `E` 就检测周围的地雷数量，有地雷就把 `E` 改为周围对应的地雷数量，如果周围没有地雷就把它改成 `B`，然后接着 `递归` 周围的格子
 注意：这里的周围指的是 **8** 个方向，递归 的时候也是需要 `递归` **8** 个方向。

  


# O 谁是19王

我们总能只通过整体交换一些行或一些列，使得已有的 $n$ 个棋子排布在对角线上。可以发现，在交换过后的棋盘上再摆 $n$ 个合法的棋子，再整体还原为一开始的排布后，这 $n$ 个新的棋子仍然合法，且反之亦然。

因此题目变为：在每一行都放一个棋子，且第 $i$ 行的棋子不能放在第 $i$ 列，同时棋子两两不在同一列。这是一个典型的 [错排问题](https://oi-wiki.org/math/combination/#_11)，利用错排公式计算出的 $f(n)$ 就是答案。



# P 智能复读机

简单的字符串模拟题。

1.记得处理行尾`\r`和`\n`；

2.出现$P$同学讲话后需要复读的情况，把复读内容换成`xjj!`即可；

3.出现$P$同学讲话后需要复读的情况，由于$T$同学说话格式给定，按照格式取出复读内容，按规定复读即可；

4.出现被$P$同学迫害的情况，把复读内容按规定换成`ShaGuangFuHuaRen`、`GaoTu`或`?`即可。

## 示例代码

```c
#include <stdio.h>
#include <string.h>
void F(char Former[]);
void G(char Former[]);
void C(char Former[]);
char T(char instr[],char Former[]);
int main()
{
	char instr[510],FormerText[510]= {0};
	char GroupID[3][25]= {0};
	char Speaker,FormerSpeaker='A',Victim;
	int len;
	while(fgets(instr,503,stdin)!=NULL)
	{
		len=strlen(instr);
		while(instr[len-1]=='\n'||instr[len-1]=='\r')
			instr[--len]=0;
		Speaker=instr[0];
		switch(Speaker)
		{
			case 'F':
			{
				if(FormerSpeaker=='P')
					strcpy(FormerText,"xjj!");
				else if(FormerSpeaker=='T'&&Victim=='F')
					strcpy(FormerText,"ShaGuangFuHuaRen");
				F(FormerText);
				printf("F:%s\n",FormerText);
				break;
			}
			case 'G':
			{
				if(FormerSpeaker=='P')
					strcpy(FormerText,"xjj!");
				else if(FormerSpeaker=='T'&&Victim=='G')
					strcpy(FormerText,"GaoTu");
				G(FormerText);
				printf("G:%s\n",FormerText);
				break;
			}
			case 'C':
			{
				if(FormerSpeaker=='P')
					strcpy(FormerText,"xjj!");
				else if(FormerSpeaker=='T'&&Victim=='C')
					strcpy(FormerText,"?");
				C(FormerText);
				printf("C:%s\n",FormerText);
				break;
			}
			case 'T':
				Victim=T(instr,FormerText);
				break;
			default:
				strcpy(FormerText,instr+2);
		}
		FormerSpeaker=Speaker;
	}
	return 0;
}
void F(char Former[])
{
	int len=strlen(Former);
	Former[len++]=')';
	Former[len++]='\0';
	while(len>0)
	{
		Former[len]=Former[len-1];
		len--;
	}
	Former[0]='(';
}
void G(char Former[])
{
	char str_G[510]="BuZhun";
	strcat(str_G,Former);
	strcpy(Former,str_G);
}
void C(char Former[])
{
	char str_C[6]="Grass";
	strcat(Former,str_C);
}
char T(char instr[],char Former[])
{
	int len;
	strcpy(Former,instr+11);
	len=strlen(Former);
	Former[--len]='\0';
	return instr[8];
}
```

