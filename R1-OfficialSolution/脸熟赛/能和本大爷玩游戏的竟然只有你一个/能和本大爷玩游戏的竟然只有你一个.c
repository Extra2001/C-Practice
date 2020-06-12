#include<stdio.h>
#define M 100
int Stein1(char* T)
{
	int ret=-1;
	if(T[0]=='j') return 52;
	if(T[0]=='J') return 53;
	if(T[0]=='S') ret+=0;
	if(T[0]=='H') ret+=13;
	if(T[0]=='D') ret+=26;
	if(T[0]=='C') ret+=39;
	if(T[1]=='A') ret+=1;
	else if(T[1]=='1') ret+=10;
	else if(T[1]=='J') ret+=11;
	else if(T[1]=='Q') ret+=12;
	else if(T[1]=='K') ret+=13;
	else ret+=(int)(T[1]-'0');
	return ret;
}
void Stein2(int x)
{
	if(x==52) printf("joker ");
	if(x==53) printf("JOKER ");
	if(x==52||x==53) return;
	if(x/13==0) printf("S");
	if(x/13==1) printf("H");
	if(x/13==2) printf("D");
	if(x/13==3) printf("C");
	if(x%13==0) printf("A ");
	else if(x%13==10) printf("J ");
	else if(x%13==11) printf("Q ");
	else if(x%13==12) printf("K ");
	else printf("%d ",(x%13)+1);
}
int begin[2][105];
int queue[2][105],Gate[100];
int top,st[2],ed[2];
char T[10];
int out(int q)
{
	int ret=queue[q][st[q]];
	st[q]=(st[q]+1)%M;
	return ret;
}
void insert(int q,int x)
{
	queue[q][ed[q]]=x;
	ed[q]=(ed[q]+1)%M;
}
int win(int q){return st[q]==ed[q];}
int main()
{
	int i,j,t,Q,K,q=1;
	for(i=0;i<27;++i) scanf("%s",T),begin[0][i]=Stein1(T);
	for(i=0;i<27;++i) scanf("%s",T),begin[1][i]=Stein1(T);
	scanf("%d",&Q);
	while(Q--)
	{
		for(i=0;i<27;++i) queue[0][i]=begin[0][i];
		for(i=0;i<27;++i) queue[1][i]=begin[1][i];
		top=0;st[0]=st[1]=0;ed[0]=ed[1]=27,q=1;
		scanf("%d",&K);
		while(K--)
		{
			q=q^1;
			t=out(q);
			Gate[top++]=t;
			if(t==52) for(i=0;i<3&&!win(q^1);++i) insert(q,out(q^1));
			if(t==53) for(i=0;i<5&&!win(q^1);++i) insert(q,out(q^1));
			if(win(q)||win(q^1))
			{
				if(win(q)) t=q;
				else t=(q^1);
				if(t) printf("Zwin\n");
				else printf("Kurisuwin\n");
				break;
			}
			if(t==52||t==53) continue;
			for(i=top-2;i>=0;--i)
				if((Gate[i]%13)==(t%13)&&(Gate[i]!=52)&&(Gate[i]!=53))
				{
					for(j=top-1;j>=i;--j) insert(q,Gate[j]);
					top=i;
				}
		}
		if(win(q)||win(q^1)) continue;
		for(i=0;i<2;++i,printf("\n"))
			for(j=st[i];j!=ed[i];j=(j+1)%M)
				Stein2(queue[i][j]);
	}
	return 0;
}
