# 填报高考志愿 解析


| 难度 | 考点          |
| ---- | ------------- |
| 3    | 二分、bsearch |

## 题目分析

本题考查对数据的二分查找。

数据范围较大，若采用顺序查找，会获得0.3分的TLE。

本题提供两种解法，都需要先对学校的分数进行排序，之后一种是利用`bsearch`函数，由学生的分数向两侧逐步查找，保证最先找到的就是绝对值最小的学校。

另一种方法是手写一个二分查找，保证查找到比学生分数高的第一个学校，之后比较这一个学校和前一个学校的分数与学生分数的差的绝对值，取小者即可。

可以看出方法一可读性较好，逻辑很清楚；方法二稍微复杂一些，还要对一个特殊情况进行处理，但可以节省不少查找次数，在本题中方法二的耗时大约是方法一的一半。

## 示例代码

```c
//使用 bsearch
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N (int)1e5
int school[N+10],stu[N+10];
int cmp(const void *,const void *);
int main() {
	int m,n,ans=0;
	int i,j,k;
	int *tmp_j,*tmp_k;
    
	scanf("%d%d",&m,&n);
	for(i=0; i<m; i++)
		scanf("%d",&school[i]);
	for(i=0; i<n; i++)
		scanf("%d",&stu[i]);

	qsort(school,m,sizeof(int),cmp); //升序排列
	for(i=0; i<n; i++) {
		for(k=j=stu[i];; j++,k--) { //用j,k两个变量同时向两侧找，保证绝对值最小
			tmp_j=bsearch(&j,school,m,sizeof(int),cmp);
            //bsearch函数的返回值是指针，因此定义tmp_j要用int *
			tmp_k=bsearch(&k,school,m,sizeof(int),cmp);
			if(tmp_j!=NULL) { //未找到时bsearch返回NULL
				ans+=*tmp_j-stu[i];
				break;
			}
			else if(tmp_k!=NULL) {
				ans+=stu[i]-*tmp_k;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
int cmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}
```

```c
//手写二分
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N (int)1e5
#define min(x,y) ((x)>(y)? (y): (x))
int school[N+10],stu[N+10];
int cmp(const void *,const void *);
int main() {
	int m,n,ans=0;
	int i;
	scanf("%d%d",&m,&n);
	for(i=0; i<m; i++)
		scanf("%d",&school[i]);
	for(i=0; i<n; i++)
		scanf("%d",&stu[i]);

	qsort(school,m,sizeof(int),cmp);//升序排列
	for(i=0; i<n; i++) {
		int l=0,r=m-1;//定义左边界与右边界
		//二分出第一个比stu[i]大的数
		while(l<r) {
			int mid=(l+r)/2;//取查找范围的中间值
			if(school[mid]<=stu[i]) { //如果录取分数线数组中的第mid个元素小于或等于那位同学的分数
				l=mid+1;//左边界右移
			} else {
				r=mid;//右边界左移
			}
		}
		if(stu[i]<=school[0]) {//此时l=0 l-1越界 需要单独处理
			ans+=school[0]-stu[i];
		} else {
			ans+=min(fabs(school[l-1]-stu[i]),fabs(school[l]-stu[i]));//加上两个绝对值中最小
		}
	}
	printf("%d\n",ans);
	return 0;
}
int cmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}
```

