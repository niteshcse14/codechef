#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
vector < pair < int, int > > adj[maxn];
int n, m, q, t;
int main(){
	int u, v;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 1; i <= m; ++i){
			scanf("%d%d", &u, &v);
			adj[u].push_back(make_pair(v, i));
		}
		
		for(int j = 1; j <= n; ++j){
			for(int i = 0; i < adj[j].size(); ++i){
				printf("%d  %d  ", j, i);
				cout << adj[j][i].fir st << "  " <<  adj[j][i].second << "\n";
			}
		}
	}
	return 0;
}