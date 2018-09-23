#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define maxn 100010
ll mx, mul, n, t, m;
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
	//pre();
	string s, st;
	scanf("%llu", &t);
	assert(t >=1 and t <= 100);
	while (t--) {
		cin >> s >> st;
		for (int i = 0; i < s.size(); ++i)
			n = (n + (s[i] - '0') % 3) % 3;
		for (int i = 0; i < st.size(); ++i)
			m = (m + (st[i] - '0') % 3) % 3;
		//scanf("%llu%llu", &n, &m);
		printf("%llu\n", (n * m) % 3);
	}
	return 0;
}