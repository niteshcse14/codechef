#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll unsigned long long int
ll n, k;
ll power(ll x, ll y) {
    x = x % mod;
    y = y % mod;
    ll res = 1;
    while (y) {
        if (y & 1)
            res = ((res * 1ULL * x % mod + mod) % mod + mod) % mod;
        y >>= 1;
        x = ((x * 1ULL * x % mod + mod) % mod + mod) % mod;
    }
    return (res % mod + mod) % mod;
}
int main() {
	scanf("%lld%lld", &n, &k);
	n--;
	ll deno = power(2, n) % mod;
	ll nume = (deno - n - 1 + mod) % mod;
	ll res = (nume * power(deno, mod - 2) % mod + mod) % mod;
	printf("%llu\n", res);
	return 0;
}