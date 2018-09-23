#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define all(a) a.begin(), a.end()
ll t, a, b, n, cnt, d, temp, mn, ans;
bool isPrime(ll num) {
	for (ll i = 2; i * i <= num; ++i)
		if (num % i == 0) return false;
	return true;
}
ll power(ll x, ll y) {
	ll out = 1;
	while (y > 0) {
		if (y & 1) out = (out * x) % d;
		y >>= 1;
		x = (x * x) % d;
	}
	return out;
}
ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}
int main() {
	scanf("%lld", &t);
	while (t--) {
		ans = 1;
		map<ll, ll> mp_a, mp_b, mp_d, res;
		vector <ll> fac_a, fac_b, fac_d;
		scanf("%lld%lld%lld", &a, &b, &n);
		d = abs(a - b);
		if (d == 0) {
			d = mod;
			ans = (power(a, n % (mod - 1)) + power(b, n % (mod - 1))) % mod;
		}
		else ans = gcd(d, (power(a, n % (d - 1)) + power(b, n % (d - 1))) % d) % mod;
		printf("%lld\n", ans);
		/*
		for (ll i = 2; i * i <= a; ++i) {
			if (a % i == 0) {
				if (isPrime(i)) fac_a.pb(i);
				if (i * i != a && isPrime(a / i)) fac_a.pb(a / i);
			}
		}
		for (ll i = 1; i * i <= b; ++i) {
			if (b % i == 0) {
				if (isPrime(i)) fac_b.pb(i);
				if (i * i != b && isPrime(b / i)) fac_b.pb(b / i);
			}
		}
		for (ll i = 1; i * i <= d; ++i) {
			if (d % i == 0) {
				if (isPrime(i)) fac_d.pb(i);
				if (i * i != d && isPrime(d / i)) fac_d.pb(d / i);
			}
		}
		sort(all(fac_a));
		sort(all(fac_b));
		sort(all(fac_d));
		for (auto i : fac_a) {
			if (i < 2) continue;
			cnt = 0;
			while (a % i == 0 && a > 1) {
				a /= i;
				cnt++;
			}
			//printf("%lld %lld %lld\n", i, cnt, n);
			mp_a[i] = (cnt * n + mod) % (mod);
		}
		for (auto i : fac_b) {
			if (i < 2) continue;
			cnt = 0;
			while (b % i == 0 && b > 1) {
				b /= i;
				cnt++;
			}
			mp_b[i] = (cnt * n + mod) % (mod);
		}
		for (auto i : fac_d) {
			if (i < 2) continue;
			cnt = 0;
			while (d % i == 0 && d > 1) {
				d /= i;
				cnt++;
			}
			mp_d[i] = cnt;
		}
		mn = LLONG_MAX;
		for (auto i : fac_d) {
			if (i < 2) continue;
			if ((mp_a.find(i) != mp_a.end()) && (mp_b.find(i) != mp_b.end())) {
				mn = min(min(mp_a[i], mp_b[i]), mp_d[i]);
				res[i] = mn;
				mp_a[i] = (mp_a[i] - mn + mod) % (mod);
				mp_b[i] = (mp_b[i] - mn + mod) % (mod);
				mp_d[i] = (mp_d[i] - mn + mod) % (mod);
			}
		}
		for (auto i : res) {
			//printf("mul  %lld %lld\n", i.f, i.s);
			ans = (power(i.f, i.s % (mod - 1)) * ans % mod + mod) % mod;
		}
		a = b = d = 1;
		for (auto i : fac_a) {
			a = (a * power(i, mp_a[i] % (mod - 1)) % mod + mod) % mod;
		}
		for (auto i : fac_b) {
			b = (b * power(i, mp_b[i] % (mod - 1)) % mod + mod) % mod;
		}
		for (auto i : fac_d) {
			d = (d * power(i, mp_d[i] % (mod - 1)) % mod + mod) % mod;
		}
		*/
		//printf("last ans %lld\n", ans);
		//printf("a = %lld b = %lld  d = %lld\n", a, b, d);
		//printf("last sum %lld %lld\n", (a + b), d);
		//ans = ((ans * __gcd((a + b + mod) % mod, d)) % mod + mod) % mod;
		/*
		printf("For a \n");
		for (auto i : mp_a) {
			printf("yes %lld %lld\n", i.f, i.s);
		}
		printf("\n");
		printf("for b \n");
		for (auto i : mp_b) {
			printf("%lld %lld\n", i.f, i.s);
		}
		printf("\n");
		printf("for d\n");
		for (auto i : mp_d) {
			printf("%lld %lld\n", i.f, i.s);
		}
		printf("\n");
		for (auto i : res) {
			printf("%lld %lld\n", i.f, i.s);
		}
		printf("\n");
		*/
		//printf("%lld\n", ans % mod);
	}
	return 0;
}