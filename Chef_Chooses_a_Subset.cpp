#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn=1e5+10;
typedef long long int lli;
lli n,u,v,ans,t;
lli parent[maxn],par[maxn],sz[maxn];
vector<lli>adj[maxn];
void dfs(lli curr,lli prev){
    parent[curr]=prev;
    for(lli i=0;i<adj[curr].size();++i)
        if(adj[curr][i]!=parent[curr])
            dfs(adj[curr][i],curr);
}
lli Find(lli curr){
    if(curr==par[curr])
        return curr;
    return par[curr]=Find(par[curr]);
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;++i)adj[i].clear();
        for(lli i=0;i<n-1;++i){
            scanf("%lld%lld",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,1);
        ans=n;
        for (int i = 1; i<= n; ++i)
            printf("%d %lld\n", i, parent[i]);
        for(lli u=1;u<=n;++u){
            //printf("For  %lld\n", u);
            for(lli v=u;v<=n;v=((v+1)|u)){
                //printf("%lld ", v);
                par[v]=v;
                sz[v]=1;
            }
            //printf("\n");
            lli maxi=1;
            for(lli v=u;v<=n;v=((v+1)|u)){
                lli w=parent[v];
                if((w&u)==u){
                    lli pv=Find(v);
                    lli pw=Find(w);
                    if(pv!=pw){
                        par[pw]=pv;
                        sz[pv]+=sz[pw];
                        maxi=max(maxi,sz[pv]);
                    }
                }
            }
            //printf("For %lld  %lld\n", u, maxi);
            lli temp=lli(maxi)*lli(u);
            ans=max(ans,temp);
        }
        //printf("%lld\n",ans);
    }
    return 0;
} 