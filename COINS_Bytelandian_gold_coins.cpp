#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 6;
map <int, ll> ans;
ll solve(ll n) {
        ll val;
        if(n == 0) {
                return 0;
        }
        if(n == 1) {
                return 1;
        }
        if(ans[n] > 0) {
                return ans[n];
        }
       else {
                val =  max(n, (solve(n / 2) + solve(n / 3) + solve(n / 4)));
                ans[n] = val;
                return val;
       }
}
int main() {
        ll n;
        while(scanf("%lld", &n) != EOF) {
                printf("%lld\n", solve(n));
        }
        return 0;
}
