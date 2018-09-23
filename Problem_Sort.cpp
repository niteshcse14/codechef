#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(a) a.begin(), a.end()
#define pb push_back
#define f first
#define s second
#define maxn 1000010
ll n, s, temp, cout_res;
struct struct_node {
	ll score, solution;
	struct_node() : score(-1), solution(-1) {};
};
struct_node ar[50];
vector<struct_node> inp[maxn];
vector<pair <ll, ll>> output;
bool comp_sort(struct_node a, struct_node b) {
	return a.score < b.score;
}
int main() {
	scanf("%lld%lld", &n, &s);
	for (ll i = 0; i < n; ++i) {
		output.pb({0, i + 1});
		for (ll j = 0; j < s; ++j)
			scanf("%lld", &ar[j].score);
		for (ll j = 0; j < s; ++j)
			scanf("%lld", &ar[j].solution);
		for (ll j = 0; j < s; ++j)
			inp[i].pb(ar[j]);
		sort(all(inp[i]), comp_sort);
	}
	for (ll i = 0; i < n; ++i) {
		cout_res = 0;
		for (ll j = 0; j < (s - 1); ++j) {
			if (inp[i][j].solution > inp[i][j + 1].solution) cout_res++;
		}
		output[i].f = cout_res;
	}
	sort(all(output));
	for (ll i = 0; i < n; ++i) 
		printf("%lld\n", output[i].s);
	return 0;
}