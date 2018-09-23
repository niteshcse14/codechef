#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long int
#define maxn 100010
ll n, s, t, low, hi_end, k, sum, l, r, y, res;
int main() {
	scanf("%lld", &t);
    while (t--) {
    	scanf("%lld%lld", &n, &s);
        vector < pair <ll, ll> > inp(n);
        for (ll i = 0; i < n; i++) {
            cin >> inp[i].f;
            inp[i].s = i;
        }
        sort(inp.begin(), inp.end());
        low = 0;
        hi_end = n;
        while (low <= hi_end) {
            k = (low + hi_end) >> 1;
            sum = 0;
            vector <ll> st(2*n, 0);
            for (ll i = 0; i < n; ) {
                ll j = i + 1;
                while (inp[i].f == inp[j].f && j < n)
                    j++;
                for (ll x = i; x < j; ) {
                    l = max(0ll, inp[x].s - k), r;
                    y = x + 1;
                    while (y < j && min(inp[y - 1].s + k, n - 1) >= inp[y].s) y++;
                    r = min(inp[y - 1].s + k, n - 1) + 1;
                    res = LLONG_MIN;
                    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) res = max(res, st[l++]);
                        if (r & 1) res = max(res, st[--r]);
                    }
                    for (ll idx = x; idx < y; idx++) {
                        ll temp = inp[idx].s;
                        for (st[temp += n] = res + 1; temp > 1; temp >>= 1)
                            st[temp >> 1] = max(st[temp], st[temp ^ 1]);
                    }
                    x = y;
                }
                i = j;
            }
            for (ll i = 0; i < n; i++)
                sum += st[i + n];
            if (sum <= s) low = k + 1;
            else hi_end = k - 1;
        }
        cout << low << '\n';
    }
    return 0;
}