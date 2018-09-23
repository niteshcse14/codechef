#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 111111;
vector < vector < pair < ll, ll > > > adj;
ll visited[maxn];
ll depth[maxn];
ll t, a, b, w, n, mx;
ll dp[30][maxn];
ll lgx = 0;
ll wt[maxn];
map < ll , map < ll , ll > > mp;
bool dfs(ll u){
	visited[u] = 1;
	vector < pair < ll, ll > > :: iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
		if(visited[(*itr).first] != 1){
			depth[(*itr).first] = depth[u] + 1;
			dp[0][(*itr).first] = u;
			wt[(*itr).first] = (*itr).second;
			dfs((*itr).first);
		}
	}
}
ll lca(ll a, ll b){
	if(depth[a] > depth[b]){
		swap(a, b);
	}
	ll diff = depth[b] - depth[a];
	for(ll i = 0; i < lgx; ++i){
		if(diff & (1 << i)){
			b = dp[i][b];
		}
	}
	if(a == b){
		return a;
	}
	for(ll i = lgx - 1; i >= 0; --i){
		if(dp[i][a] != dp[i][b]){
			a = dp[i][a];
			b = dp[i][b];
		}
	}
	return dp[0][a];
}
ll max(ll a, ll b){
	return a > b ? a : b;
}
ll mex_weight(ll u, ll v, ll D){
	ll lc = lca(u, v);
	mx = D;
	while(u != lc){
		mx = max(mx, wt[u] ^ D);
		u = dp[0][u];
	}
	while(v != lc){
		mx = max(mx, wt[v] ^ D);
		v = dp[0][v];
	}
	return mx;
}
int main(){
	ll D;
	freopen("input.txt", "r", stdin);
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		adj.clear();
		adj.resize(n);
		lgx = log(n) / log(2) + 1;
		for(ll i = 0; i < lgx; ++i){
			for(ll j = 0; j < n; ++j){
				dp[i][j] = 0;
				visited[j] = 0;
				depth[j] = 0;
				wt[j] = 0;
			}
		}
		for(ll i = 0; i < n - 1; ++i){
			scanf("%lld%lld%lld", &a, &b, &w);
			a--;
			b--;
			mp[a][b] = w;
			mp[b][a] = w;
			adj[a].push_back(make_pair(b, w));
			adj[b].push_back(make_pair(a, w));
		}
		dfs(0);
		for(ll i = 1; i < lgx; ++i){
			for(ll j = 0; j < n; ++j){
				dp[i][j] = dp[i - 1][dp[i - 1][j]];
			}
		}
		ll q;
		scanf("%lld", &q);
		while(q--){
			scanf("%lld%lld%lld", &a, &b, &D);
			a--;
			b--;
			printf("%lld\n", mex_weight(a, b, D));
		}
	}
	return 0;
}