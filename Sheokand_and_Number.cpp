#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000010
#define maxn 1000010
#define ll long long int
ll t, n, sz, tt, res;
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		res = MAXN;
		for (ll i = 0; i <= 31; ++i) {
			for (ll j = i + 1; j <= 31; ++j) {
				tt = (1 << i) + (1 << j);
				if (tt >= n) res = min(res, tt - n);
				else res = min(res, n - tt);
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}