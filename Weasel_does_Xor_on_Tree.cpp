#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 2 * 1e5 + 5;
ll n, q, a, b, odd = 0, even = 0;
vector < ll > adj[maxn];
ll arr[maxn];
ll sum, idx;
ll dp[maxn];
void dfs(ll u){
	vector < ll > :: iterator itr, itr1;
	for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
		dfs(*itr);
		sum = arr[*itr];
		for(itr1 = adj[*itr].begin(); itr1 != adj[*itr].end(); ++itr1){
			sum ^= arr[*itr1];
		}
		arr[*itr] = sum;
	}
}
ll all_xor(){
	ll s = arr[0];
	for(ll i = 0; i < adj[0].size(); ++i){
		s ^= arr[adj[0][i]];
	}
	return s;
}
int main(){
	//freopen("input.txt", "r", stdin);
	memset(dp, 0, sizeof(dp));
	scanf("%lld%lld", &n, &q);
	for(ll i = 0; i < n - 1; ++i){
		scanf("%lld%lld", &a, &b);
		adj[a].push_back(b);
	}
	odd = 0;
	for(ll i = 0; i < n; ++i){
		scanf("%lld", &arr[i]);
		odd ^= arr[i];
	}
	dfs(0);
	arr[0] ^= all_xor();
	dp[0] = arr[0];
	for(ll i = 1; i <= 5; ++i){
		dfs(0);
		dp[i] = dp[i - 1] ^ all_xor();
		printf("allxor  %lld  %lld  %lld\n", all_xor(), dp[i], dp[i - 1]);
	}
	for(ll i = 0; i < q; ++i){
		scanf("%lld", &idx);
		idx--;
		printf("%lld\n", dp[idx]);
	}
	return 0;
} 