#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100010
ll n, t, res, num, mx, k, x, mn;
ll inp[maxn];
ll sum(ll val) {
	return (val * (val + 1)) / 2;
}
int main() {
	scanf("%lld", &t);
	while (t--) {
		res = mx = 0;
		mn = LLONG_MAX;
		inp[0] = 0;
		scanf("%lld%lld%lld", &n, &k, &x);
		for (ll i = 1; i <= k; ++i) {
			scanf("%lld", &inp[i]);
			res += inp[i];
			mx = max (mx, inp[i]);
			mn = min(mn, inp[i]);
		}
		sort (inp, inp + k + 1);
		//for (ll i = 1; i <= k; ++i)
		n -= k;
		//printf("now n is %lld\n", n);
		ll diff = mx - mn;
		mx = x + mn;
		if (mx != inp[k]) {
			num = mx - inp[k];
			//printf("res %lld\n", res);
			//printf("num is %lld  %lld %lld\n", num, inp[i], inp[i - 1]);
			if (num >= n) {
				res += sum(mx) - sum(mx - n);
				//printf("if res %lld %lld %lld\n", res,  mx, mx - n);
				n = 0;
			}
			else {
				res += sum(mx) - sum(mx - num);
				//printf("else res %lld %lld %lld\n", res,  mx, mx - num);
				n -= num;
			}
		}
		for (ll i = k; i >= 1 && n > 0; --i) {
			if ((inp[i] - 1) == inp[i - 1]) continue;
			num = inp[i] - inp[i - 1] - 1;
			//printf("num is %lld  %lld %lld\n", num, inp[i], inp[i - 1]);
			if (num >= n) {
				res += sum(inp[i] - 1) - sum(inp[i] - n - 1);
				//printf("sum  %lld %lld\n", sum(inp[i] - 1), sum(inp[i] - n - 1));
				n = 0;
			}
			else {
				res += sum(inp[i] - 1) - sum(inp[i] - num - 1);
				//printf("sum  %lld %lld\n", sum(inp[i] - 1), sum(inp[i] - num - 1));
				n -= num;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
//10 9 8 7 6 5 4 1
// 15 _ 13 _ 11 _ 9 _ _ 6
// 15 14 13 12 11 10 9 8 7 6
// 11 * 6