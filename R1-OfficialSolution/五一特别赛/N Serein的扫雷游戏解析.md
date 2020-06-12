# N Serein的扫雷游戏


| 难度 | 考点          |
| ---- | ----        |
| 4  |    搜索     |

## 题目分析

- 遇到 `E` 就检测周围的地雷数量，有地雷就把 `E` 改为周围对应的地雷数量，如果周围没有地雷就把它改成 `B`，然后接着 `递归` 周围的格子
  注意：这里的周围指的是 **8** 个方向，递归 的时候也是需要 `递归` **8** 个方向。

  

## 示例代码

```c
#include<stdio.h>
#define MAX_N 10500
int N,M,sx,sy,i,j;
char s[10];
char field[MAX_N][MAX_N+1];
int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
int count(int x,int y){
	int tmp=0;
	for(i=0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(0<=nx&&nx<N&&0<=ny&&ny<M&&field[nx][ny]=='M') tmp++;
	}
	return tmp;
}
void dfs(int x,int y){
	if(x<0||x>=N||y<0||y>=M) return ;
	if(field[x][y]=='E'){
		field[x][y]='B';
		int cnt=count(x,y);
		if(cnt==0){
			for(int i=0;i<8;i++){
				dfs(x+dx[i],y+dy[i]);
			}
		}else field[x][y]=cnt+'0';
	}else if(field[x][y]=='M'){
		field[x][y]='X';
	}
}
void print(){
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%c",field[i][j]);}
		if(i!=N-1)	printf("\n");
	}
}
int main(void){
	scanf("%d%d",&N,&M);
	gets(s);
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%c",&field[i][j]);}
			gets(s);}
	scanf("%d%d",&sx,&sy);
	dfs(sx,sy);			
	print();
    return 0;
}
```



