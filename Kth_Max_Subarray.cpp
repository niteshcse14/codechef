#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll t, n, k, q;
ll arr[maxn];
vector < ll > prefix_sum;
ll bs_idx(ll idx){
	ll l = 0;
	ll r = n - 1;
	ll mid, res = 0;
	while(l < r){
		mid = (l + r) / 2;
		if(prefix_sum[mid] >= idx){
			r = mid;
		}
		else{
			l = mid + 1;
		}
		//printf("l  %lld  r   %lld  mid  %lld\n", l, r, mid);
	}
	return r;
}
int main(){
	scanf("%lld", &t);
	while(t--){
		prefix_sum.clear();
		scanf("%lld%lld", &n, &q);
		for(int i = 0; i < n; ++i){
			scanf("%lld", &arr[i]);
		}
		sort(arr, arr + n, greater < int > ());
		ll sum = 0;
		for(ll i = n; i > 0; --i){
			sum += i;
			prefix_sum[n - i] = sum;
		}
		while(q--){
			scanf("%lld", &k);
			//printf("%lld\n", bs_idx(k));
			int idx = lower_bound(prefix_sum.begin(), prefix_sum.end(), k) - prefix_sum.begin();
			printf("%lld\n", arr[idx]);
		}
	}
	return 0;
}