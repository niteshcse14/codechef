#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 5;
vector < int > adj[maxn];
int euler[maxn];
int level[maxn];
int parent[maxn];
int depth[maxn];
int idx = 0;
int n;
bool visited[maxn];
void dfs(int u, int prev, int dep)
{
	parent[u] = prev;
	euler[idx++] = u;
	depth[u] = dep;
	visited[u] = true;
	vector<int>::iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
		if(!visited[*itr])
		{
			dfs(*itr, u, dep + 1);
		}
	}
	euler[idx++] = euler[parent[u]];
}
int main(){
	int u, v;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1, 0);
	for(int i = 0; i < idx; ++i){
		printf("%d  ", euler[i]);
	}
	printf("\n");
	for(int i = 0; i < idx; ++i){
		//printf("%d  ", level[i]);
	}
	//printf("\n");
	for(int i = 1; i <= n; ++i){
	//	printf("%d  ", parent[i]);
	}
	//printf("\n");
	return 0;
}