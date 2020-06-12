#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int N=100005;
int n,m,r,p,tot,dcnt,q;
int w[N],head[N*2],mp[N];
struct NODE{
    int to,nex;
}ed[N*2];
struct node{
    int fa,son,sz,dep,top,s,e;
}tr[N];//Ê÷Á´ÆÊ·Ö
struct Segtree{
   int l,r;
   int sum,lazy,maxx;
}tree[4*N];
inline void addedge(int x,int y){
    ++tot;
    ed[tot].nex=head[x];
    head[x]=tot;
    ed[tot].to=y;
}
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
void dfs1(int u){
    tr[u].sz=1;
    for(int i=head[u];i;i=ed[i].nex)
       if(ed[i].to!=tr[u].fa){
             tr[ed[i].to].fa=u;
             tr[ed[i].to].dep=tr[u].dep+1;
             dfs1(ed[i].to);
             tr[u].sz+=tr[ed[i].to].sz;
             if(tr[ed[i].to].sz>tr[tr[u].son].sz){
                  tr[u].son=ed[i].to;
             }
    }
}
void dfs2(int u,int top){
    tr[u].top=top;
    tr[u].s=++dcnt;
    mp[dcnt]=u;
    if(tr[u].son){
        dfs2(tr[u].son,top);
        for(int i=head[u];i;i=ed[i].nex)
         if(ed[i].to!=tr[u].fa&&ed[i].to!=tr[u].son)
         dfs2(ed[i].to,ed[i].to);        
    }
    tr[u].e=dcnt;
}
inline void update(int b){
    tree[b].sum=tree[b*2].sum+tree[b*2+1].sum;
    tree[b].maxx=max(tree[b*2].maxx,tree[b*2+1].maxx);
}
void build(int b,int l,int r){
    tree[b].l=l;
    tree[b].r=r;
    if(l==r){
        tree[b].sum=tree[b].maxx=w[mp[l]];
        return ;
    }
    int mid=l+r>>1;
    build(b*2,l,mid);
    build(b*2+1,mid+1,r);
    update(b);
}
int qsum(int id,int l,int r)
{
    if(tree[id].l>r || tree[id].r<l)return 0;
    if(tree[id].l>=l && tree[id].r<=r)return tree[id].sum;
    return (qsum(id*2,l,r)+qsum(id*2+1,l,r));
}
int qmax(int id,int l,int r){
    int ans=-1e9;
    if(tree[id].l>r || tree[id].r<l)return -1e9;
    if(tree[id].l>=l && tree[id].r<=r)return max(ans,tree[id].maxx);
    return max(qmax(id*2,l,r),qmax(id*2+1,l,r));
}
int query(int x,int y){
    int f1=tr[x].top;
    int f2=tr[y].top;
    int ans=0;
    while(f1!=f2){
        if(tr[f1].dep<tr[f2].dep){
            swap(x,y);
            swap(f1,f2);
        }
        ans+=qsum(1,tr[f1].s,tr[x].s);
        x=tr[f1].fa;
        f1=tr[x].top;
    }
    if(tr[x].dep>tr[y].dep) swap(x,y);    
    return ans=ans+qsum(1,tr[x].s,tr[y].s);
}
int find(int x,int y){
    int f1=tr[x].top;
    int f2=tr[y].top;
    int ans=-10000000;
    while(f1!=f2){
        if(tr[f1].dep<tr[f2].dep){
            swap(x,y);
            swap(f1,f2);
        }
        ans=max(ans,qmax(1,tr[f1].s,tr[x].s));
        x=tr[f1].fa;
        f1=tr[x].top;
    }
    if(tr[x].dep<tr[y].dep)
     ans=max(ans,qmax(1,tr[x].s,tr[y].s));
    else 
      ans=max(ans,qmax(1,tr[y].s,tr[x].s));
    return ans;
}
void change(int b,int x,int y,int z){
    if(y<tree[b].l||x>tree[b].r) return ;
    if(tree[b].l==tree[b].r){
        tree[b].maxx=z;
        tree[b].sum=z;
        return ;
    }
    change(b*2,x,y,z);
    change(b*2+1,x,y,z);
    update(b);
}
main(){
    n=read();
    for(int i=1;i<n;i++){
      int x,y;
      x=read();
      y=read();
      addedge(x,y);
      addedge(y,x);
    }
    for(int i=1;i<=n;i++)  w[i]=read();
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    q=read();
    for(int i=1;i<=q;i++){
        string mode;
        int x,y,z;
        cin>>mode;
        if(mode=="QSUM")
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",query(x,y));
        }
        else if(mode=="CHANGE")
        {
            scanf("%lld%lld",&x,&z);
            change(1,tr[x].s,tr[x].s,z);
        }
        else if(mode=="QMAX")
        {
            scanf("%lld%lld",&x,&y); 
            printf("%lld\n",find(x,y));
        }
    }
    return 0;
}
