#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef pair < int, int > PII;
vector < PII > adj[maxn];
int t, n, m, S, T, V, a, b, c, ans;
int vis[maxn];
void dfs (int u, int sum = 0) {
	vis[u] = 1;
	printf("%d %d %d %d %d\n", u, vis[S], vis[T], vis[V], sum);
	if (vis[S] == 1 && vis[T] == 1 && vis[V] == 1) {
		printf("Hello\n");
		ans = min (ans, sum);
	}
	vector < PII > :: iterator itr;
	for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {
		if (!vis[(*itr).first]) {
			dfs ((*itr).first, sum + (*itr).second);
		}
	}
	printf("\n");
	//vis[u] = 0;
}
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &n, &m);
		scanf ("%d%d%d", &S, &T, &V);
		for (int i = 0; i < m; ++i) {
			scanf ("%d%d%d", &a, &b, &c);
			adj[a].push_back (make_pair (b, c));
			adj[b].push_back (make_pair (a, c));
		}
		ans = INT_MAX;
		memset (vis, 0, sizeof (vis));
		dfs (S);
		printf("%d\n", ans);
	}
	return 0;
}