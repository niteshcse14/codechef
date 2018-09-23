#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > adj[maxn];
int color[maxn], sum;
void dfs(bool visited[], int u, int clr){
	if(color[u] != clr){
		//printf("true  %d\n", u);
		return;
	}
	sum++;
	// printf("%d  ", u);
	visited[u] =  true;
	vector < int > :: iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
		if(!visited[*itr]){
			dfs(visited, *itr, clr);
		}
	}
}
int main(){
	int n, u, v, type, q;
	bool visited[maxn];
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		scanf("%d%d", &u, &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &type, &u);
		u--;
		if(type == 0){
			sum = 0;
			memset(visited, false, sizeof(visited));
			int clr = color[u];
			dfs(visited ,u, clr);
			printf("%d\n", sum);
		}
		else if(type == 1){
			color[u] ^= 1;
		}
	}
	return 0;
}