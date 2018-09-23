    #include <bits/stdc++.h>
    using namespace std;
    #define ll unsigned long long int
    #define pb push_back
    #define all(a) a.begin(), a.end()
    #define maxn 5010
    #define mod 1000000007
    ll n, t, k, res, temp, res_a;
    ll inp[maxn], arr[maxn], dp[maxn][maxn], ar[maxn];
    ll min(ll a, ll b) {
        return (a < b) ? a : b;
    }
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
    void solve() {
        for (ll i = 0; i <= 5000; i++) {
            for (ll j = 0; j <= min(i, 5000); j++) {
                if (j == 0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % (mod - 1);
            }
        }
    }
    int main() {
        solve();
        scanf ("%llu", &t);
        assert (t >= 1 and t <= 10);
        while (t--) {
            scanf ("%llu%llu", &n, &k);
            assert(k >= 3 and k <= k);
            ll tot = dp[n - 1][k - 1];
            for (int i = 0; i < n; ++i) {
                scanf ("%llu", &inp[i]);
                arr[i] = tot;
                ar[i] = 0;
            }
            sort (inp, inp + n);
            for (ll i = 0; i < n; ++i) {
                for (int j = i + k - 2 + 1; j < n; ++j) {
                    ll len = j - i - 1;
                    temp = (dp[len][k - 2]) % (mod - 1);
                    ar[i] = (temp + ar[i]) %  (mod - 1);
                    ar[j] = (temp + ar[j]) % (mod - 1);
                }
            }
            for (ll i = 0; i < n; ++i) 
                arr[i] = (arr[i] - ar[i] + mod - 1) % (mod - 1);
            res = 1ULL;
            for (ll i = 0; i < n; ++i)
                res = (res * 1ULL * power(inp[i], arr[i]) % mod + mod) % mod;
            printf("%llu\n", res);
        }
        return 0;
    } 