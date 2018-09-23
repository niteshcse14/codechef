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
struct queries {
	ll typ;
	ll a, b, c;
	ll ans;
	queries() : typ(-1), a(0), b(0), c(0), ans(-1) {};
};
queries qur[maxn];
subset subsets[maxn];
ll n, m, x, y, v, c, typ, ans, a, b;
bool vis[maxn], block[maxn], qur_b[maxn];
bool flag_ans, flag;
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
void false_dfs(ll cur) {
	vis[cur] = false;
	direction[cur] = 0;
	dep[cur] = 0;
	for (auto i : adj[cur])
		if (vis[i])
			false_dfs(i);
}
void walk_down(ll cur, ll velocity) {
	queue <ll> qu;
	qu.push(cur);
	//printf("node dep %lld %lld\n", cur, dep[cur]);
	while (!qu.empty()) {
		ll u = qu.front();
		qu.pop();
		for (auto i : adj[u]) {
			if (direction[u] == direction[i]) {
				flag_ans = true;
				return;
			}
			if (!vis[i]) {
				dep[i] = dep[u] + 1;
				direction[i] = -1 * direction[u];
				vis[i] = true;
				qu.push(i);
			}
		}
	}
}
void addEdge(ll u, ll v) {
	adj[u].pb(v);
	adj[v].pb(u);
}
void blocked(ll i, ll x, ll y) {
	ll xroot = Find(x);
	ll yroot = Find(y);
	qur[i].ans = 0;
	block[x] = block[xroot] = true;
	block[x] = block[yroot] = true;
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
	for (ll i = 0; i < maxn; ++i) {
		qur[i].typ = -1;
		qur[i].a = 0;
		qur[i].b = 0;
		qur[i].c = 0;
		qur[i].ans = -1;
	}
	flag = false;
	memset(direction, 0, sizeof direction);
	memset(dep, 0, sizeof dep);
	memset(vis, false, sizeof vis);
	for (ll i = 1; i <= m; ++i) {
		a = b = c = 0;
		scanf("%lld%lld%lld", &typ, &a, &b);
		if (typ == 3)
			scanf("%lld", &c);
		qur[i].typ = typ;
		qur[i].a = a;
		qur[i].b = b;
		qur[i].c = c;
	}
	for (ll i = 1; i <= m; ++i) {
		x = qur[i].a;
		y = qur[i].b;
		ll xroot = Find(x);
		ll yroot = Find(y);
		typ = qur[i].typ;
		if (xroot != yroot && typ == 3) {
			qur[i].ans = 0;
		}
		else if (qur[i].typ == 3) {
			if (block[x] || block[xroot] || block[y] || block[yroot])
				blocked(i, x, y);
		}
		if (qur[i].typ != 2)
			continue;
		flag_ans = false;
		a = subsets[xroot].rank;
		b = subsets[yroot].rank;
		if (xroot != yroot) {
			if (a <= b) {
				Union(x, y);
				false_dfs(x);
				addEdge(x, y);
				if (block[xroot] || block[yroot])
					blocked(i, x, y);
				if (direction[y] == 0)
					direction[y] = 1;
				walk_down(y, direction[y]);
			}
			else {
				Union(x, y);
				false_dfs(y);
				addEdge(x, y);
				ll new_xroot = Find(x);
				ll new_yroot = Find(y);
				if (block[xroot] || block[yroot])
					blocked(i, x, y);
				if (direction[x] == 0)
					direction[x] = 1;
				walk_down(x, direction[x]);
			}
		}
		else {
			addEdge(x, y);
			if (direction[x] == direction[y] && direction[x] != 0)
				blocked(i, x, y);
		}
		if (block[xroot] || block[yroot] || flag_ans)
			blocked(i, x, y);
	}
	for (ll i = 1; i <= m; ++i) {
		typ = qur[i].typ;
		x = qur[i].a;
		y = qur[i].b;
		v = qur[i].c;
		if (typ == 2) continue;
		if (typ == 1)
			inp[x] = y;
		else {
			if (qur[i].ans == 0) {
				printf("0\n");
				continue;
			}
			ll num = v * inp[x];
			ll den = inp[y];
			ll g = gcd(num, den);
			num /= g;
			den /= g;
			ll sg = abs(dep[x] - dep[y]);
			ll diff = sg;
			if (sg & 1)
				sg = -1;
			else 
				sg = 1;
			printf("%lld/%lld\n", sg * num, den);
		}
	}
	return 0;
}