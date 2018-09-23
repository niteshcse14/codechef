#include <bits/stdc++.h>
using namespace std;
int inp[1005][1005];
pair < int, int > iPair;
vector < int , iPair > tel_pair;
void solve(){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			solve();
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &r, &c, &n, &sx, &sy);
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &dx, &dy);
			tel_pair.push_back(make_pair(dx, dy));
		}
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				scanf("%d", &inp[i][j]);
			}
		}
	}
	return 0;
}