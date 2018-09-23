#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> v[500010];
 
int main(){
//  ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,Q,x,y,d,k,i;
    cin>>n>>Q;
    vector<ll> a(n+1);    vector<ll> lazy(n+1,0);
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    while(Q--){
        cin>>x>>y;
        lazy[x]+=y;
    }
 
    deque<int>q;
    vector<bool>visited(n+1,false);
    q.push_back(1); visited[1]=true;
    while(!q.empty() ){
        int x=q.front();
        q.pop_front();
        a[x]+=lazy[x];
        for(i=0;i<v[x].size();i++){
            int p=v[x][i];
            if( visited[p]==false ){
                q.push_back(p);
                visited[p]=true;
                lazy[p]+=lazy[x];
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
 
}