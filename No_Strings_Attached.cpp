#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pb push_back
#define ll long long int
ll t, n, res, temp, inter_change, ans, cal,temp_ch, tt, tt_ch;
char str[maxn];
ll dp[26][maxn], pre[maxn];
int main() {
	scanf ("%lld" ,&t);
	while (t--) {
		res = 0;
		memset (dp, 0, sizeof dp);
		memset (pre, 0, sizeof pre);
		scanf ("%s", str);
		n = strlen (str);
		for (ll i = 0; i < 26; ++i)
			for (ll j = 0; j < n; ++j)
				if (str[j] - 'a' == i)
					dp[i][j] = 1;

		for (ll i = 0; i < 26; ++i)
			for (ll j = 1; j < n; ++j)
				dp[i][j] = dp[i][j] + dp[i][j - 1];

		for (ll i = 0; i < n; ++i) {
			temp = 0;
			for (ll j = str[i] - 'a' + 1; j < 26; ++j) {
				temp += dp[j][n - 1] - dp[j][i];
			}
			res += temp;
			pre[i] = temp;
		}
		ans = res;
		for (ll i = 0; i < n; ++i) {
			for (ll j = 0; j < 26; ++j) {
				inter_change = abs (str[i] - 'a' - j);
				tt_ch = tt = 0;
				for (ll k = 0; k < j && i > 0; ++k) {
					tt_ch += dp[k][i - 1];
				}
				for (ll k = 0; k < (str[i] - 'a') && i > 0; ++k) {
					tt += dp[k][i - 1];
				}
				temp_ch = temp = 0;
				for (ll k = j + 1; k < 26; ++k) {
					temp_ch += dp[k][n - 1] - dp[k][i];
				}
				for (ll k = str[i] - 'a' + 1; k < 26; ++k) {
					temp += dp[k][n - 1] - dp[k][i];
				}
				cal = res - tt - temp;
				cal = cal + tt_ch + temp_ch + inter_change;
				if (cal < ans)
					ans = cal;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}