#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int LN = 18;
typedef pair < int, int > PII;
int n, m, a, b, c, ans;
int visited[maxn], pa[maxn][LN], depth[maxn];
vector < int > adj[maxn];
void dfs (int u, int prev) {
	pa[u][0] = prev;
	queue < int > qu;
	qu.push (u);
	while (!qu.empty()) {
		u = qu.front();
		qu.pop ();
		visited[u] = 1;
		for (int i = 0; i < adj[u].size(); ++i) {
			if (visited[adj[u][i]] == 0) {
				pa[adj[u][i]][0] = u;
				depth[adj[u][i]] = depth[u] + 1;
				qu.push (adj[u][i]);
			}
		}
	}
}
int lca (int u, int v) {
	if (u == v) {
		return u;
	}
	if (depth[v] < depth[u]) swap (u, v);
	int diff = depth[v] - depth[u];
	for (int i = 0; i < LN; ++i) {
		if ((diff >> i) & 1) {
			v = pa[v][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = LN - 1; i >= 0; --i) {
		if (pa[u][i] != pa[v][i]) {
			u = pa[u][i];
			v = pa[v][i];
		}
	}
	return pa[u][0];
}
int main () {
	memset (pa, -1, sizeof (pa));
	memset (visited, 0, sizeof (visited));
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf ("%d%d%d", &a, &b, &c);
		adj[a].push_back (b);
		adj[b].push_back (a);
	}
	depth[0] = 0;
	dfs (1, 0);
	for (int i = 1; i < LN; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (pa[j][i - 1] != -1) {
				pa[j][i] = pa[pa[j][i - 1]][i - 1];
			}
		}
	}
	scanf ("%d", &m);
	while (m--) {
		scanf ("%d%d", &a, &b);
		//dfs (a, pa[0][a]);
		printf("%d\n", lca (a, b));
	}
	return 0;
}