#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll arr[maxn];
ll t, n, cnt, c, sum;
set < ll > s;
void seive() {
	for (int i = 0; i < maxn; ++i) {
		
	}
}
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		cnt = 0;
		sum = 1;
		c = 0;
		s.clear();
		for(ll i = 0; i < n; ++i) {
			scanf("%lld", &arr[i]);
			s.insert(arr[i]);
			if (s.size() > c) {
				c = s.size();
				cnt++;
			}
			else {
				cnt = 0;
			}
		}
		printf("%lld\n", cnt > 1 ? cnt : -1);
	}
	return 0;
}