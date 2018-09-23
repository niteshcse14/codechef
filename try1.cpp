#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define pb push_back
#define ll long long int
struct subset {
	ll parent;
	ll rank;
	subset() : parent(-1), rank(0) {};
};
subset subsets[maxn];
ll n, m, x, y, v, c, typ, ans;
bool vis[maxn], block[maxn];
bool flag_ans;
ll inp[maxn], color[maxn], dep[maxn], direction[maxn];
vector<ll> adj[maxn];
string sign[maxn];
ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
ll Find(ll i) {
	if (subsets[i].parent != i)
		subsets[i].parent = Find(subsets[i].parent);
	return subsets[i].parent;
}
void Union(ll a,ll b) {
	ll xroot = Find(a);
	ll yroot = Find(b);
	if (xroot == yroot) return;
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
void dfs_block(ll cur) {
	block[cur] = true;
	for (auto i : adj[cur]) {
		if (!block[i])
			dfs_block(i);
	}
}
ll get(ll idx, ll dest) {
	memset(dep, 0, sizeof dep);
	queue<ll> qu;
	qu.push(idx);
	ll ch = 0;
	while (!qu.empty()) {
		ll u = qu.front();
		qu.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			dep[adj[u][i]] = dep[u] + 1;
			ll v = dep[adj[u][i]];
			if (adj[u][i] == dest)
				return v;
			if (u != adj[u][i]) {
				vis[adj[u][i]] = true;
				qu.push(adj[u][i]);
			}
		}
	}
}
bool dfs_cycle(ll cur, ll pre_clr){
	color[cur] = 1 - pre_clr;
    for (auto i : adj[cur]) {
    	if (color[cur] == color[i]) 
    		return true;
    	else if (color[i] == -1) 
    		dfs_cycle(i, color[cur]);
    }
    return false;
}
void solve(ll cur, ll vel) {
    vis[cur] = 1;
    direction[cur] = vel;
    for (auto v : adj[cur]) {
        if (!vis[v])
            solve(v, -1 * vel);
        else {
            if (direction[v] != -vel) {
                flag_ans = 1;
                return;
            }
        }
    }
}
 
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &inp[i]);
	for (int i = 0; i < maxn; ++i) {
		subsets[i].rank = 0;
		subsets[i].parent = i;
		block[i] = false;
	}
	memset(block, false, sizeof block);
	while (m--) {
		scanf("%lld", &typ);
		if (typ == 1) {
			scanf("%lld%lld", &x, &c);
			inp[x] = c;
			continue;
		}
		scanf("%lld%lld", &x, &y);
		ll xroot = Find(x);
		ll yroot = Find(y);
		if (typ == 2) {
			adj[x].pb(y);
			adj[y].pb(x);
			if (xroot != yroot)
				Union(x, y);
			/*
			memset(color, -1, sizeof color);
			if (dfs_cycle(x, 0)) {
				dfs_block(x);
				dfs_block(y);
			}
			*/
		}
		else {
			flag_ans = false;
			scanf("%lld", &v);
			//memset(vis, false, sizeof vis);
			//memset(direction, 0, sizeof direction);
			for (ll i = 1; i <= n; ++i) {
				vis[i] = 0;
				direction[i] = 0;
			}
			solve(x, 1);
			if (!direction[y] || flag_ans) {
				printf("0\n");
			}
			else {
				//printf("ELSE\n");
				ll num = v * inp[x];
				ll den = inp[y];
				ll g = gcd(num, den);
				num /= g;
				den /= g;
				printf("%lld/%lld\n", direction[y] * num, den);
			}
		}
	}
	return 0;
} 