#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100010
ll mx, mul, n, t;
ll inp[maxn], prime[maxn];
void pre() {
	for (ll i = 1; i < maxn; ++i)
		prime[i] = 1;
	for (ll i = 2; i * i <= maxn; ++i) {
		if (prime[i] == 1) {
			for (ll j = 2 * i; j < maxn; j += i)
				prime[j] = 0;
		}
	}
}
int main() {
	pre();
	scanf("%lld", &t);
	assert(t >=1 and t <= 100);
	while (t--) {
		mx = maxn;
		scanf("%lld", &n);
		assert(n >=1 and n <= 100);
		for (ll i = 0; i < n; ++i) {
			scanf("%lld", &inp[i]);
			assert(inp[i] >=1 and inp[i] <= 100);
		}
		sort(inp, inp + n);
		if (inp[0] != 1 || n == 1)
			printf("-1\n");
		else {
			mx = -1;
			for (ll i = 1; i < n; ++i) {
				if (prime[inp[i]]) {
					mx = inp[i];
					break;
				}
			}
			if (mx != -1) {
				printf("%lld\n", mx);
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}