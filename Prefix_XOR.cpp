#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>
 
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
 
using namespace std;
 
typedef long long LL;
typedef double db;
 
int get(){
    char ch;
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    if (ch=='-'){
        int s=0;
        while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
        return -s;
    }
    int s=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
    return s;
}
 
const int N = 4e5+5;
 
int n,q;
int a[N];
int pre[N];
int rmq[N][20][2];
int key[N];
struct node{
    int l,r,tot;
    LL sum1,sum2;
}tree[N*20];
int tot;
int rt[N];
 
void add(int &now,int qf,int l,int r,int x,int v1,int v2){
    tree[now=++tot]=tree[qf];
    tree[now].tot++;
    tree[now].sum1=tree[now].sum1+v1;
    tree[now].sum2=tree[now].sum2+v2;
    if (l==r)return;
    int mid=(l+r)/2;
    if (x<=mid)add(tree[now].l,tree[qf].l,l,mid,x,v1,v2);
    else add(tree[now].r,tree[qf].r,mid+1,r,x,v1,v2);
}
 
LL getsum1(int rf,int lf,int l,int r,int x,int y){
    if (y<l||r<x)return 0;
    if (x<=l&&r<=y)return tree[rf].sum1-tree[lf].sum1;
    int mid=(l+r)/2;
    LL ret=0;
    if (x<=mid)ret=getsum1(tree[rf].l,tree[lf].l,l,mid,x,y);
    if (y>mid)ret=ret+getsum1(tree[rf].r,tree[lf].r,mid+1,r,x,y);
    return ret;
}
 
LL getsum2(int rf,int lf,int l,int r,int x,int y){
    if (y<l||r<x)return 0;
    if (x<=l&&r<=y)return tree[rf].sum2-tree[lf].sum2;
    int mid=(l+r)/2;
    LL ret=0;
    if (x<=mid)ret=getsum2(tree[rf].l,tree[lf].l,l,mid,x,y);
    if (y>mid)ret=ret+getsum2(tree[rf].r,tree[lf].r,mid+1,r,x,y);
    return ret;
}
 
int gettot(int rf,int lf,int l,int r,int x,int y){
    if (y<l||r<x)return 0;
    if (x<=l&&r<=y)return tree[rf].tot-tree[lf].tot;
    int mid=(l+r)/2;
    int ret=0;
    if (x<=mid)ret=gettot(tree[rf].l,tree[lf].l,l,mid,x,y);
    if (y>mid)ret=ret+gettot(tree[rf].r,tree[lf].r,mid+1,r,x,y);
    return ret;
}
 
 
int main(){
    n=get();
    fo(i,1,n)a[i]=get();
    fo(i,1,n)pre[i]=pre[i-1]^a[i];
    fo(i,1,n){
        if (!a[i])continue;
        int x=a[i];
        while(x!=(x&-x))x-=x&-x;
        if ((pre[i]&x)>0) rmq[i][0][1]=x;
        else rmq[i][0][0]=x;
    }
    fo(j,1,log(n)/log(2))
        fo(i,1,n-(1<<j)+1)
            fo(x,0,1)
            rmq[i][j][x]=rmq[i][j-1][x]|rmq[i+(1<<(j-1))][j-1][x];
    fo(i,1,n){
        key[i]=i;
        fd(x,log(n)/log(2),0)
        if (key[i]+(1<<x)<=n&&(rmq[key[i]+1][x][1]&pre[i-1])==0&&(rmq[key[i]+1][x][0]&pre[i-1])==rmq[key[i]+1][x][0])
            key[i]+=(1<<x);
    }
    fo(i,1,n)
        add(rt[i],rt[i-1],1,n,key[i],key[i]-i+1,i);
    LL lastans=0;
    q=get();
    fo(cas,1,q){
        int l=get(),r=get();
        l=(l+lastans)%n+1;
        r=(r+lastans)%n+1;
        lastans=getsum1(rt[r],rt[l-1],1,n,1,r)+1ll*gettot(rt[r],rt[l-1],1,n,r+1,n)*(r+1)-getsum2(rt[r],rt[l-1],1,n,r+1,n);
        printf("%lld\n",lastans);
        lastans=lastans%n;
    }
    return 0;
}   