#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define maxn 100005
char str[maxn], curr;
struct node {
	ll l;
	ll r;
};
ll t, n, L, R, cnt;
vector < node > arr;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		arr.clear();
		scanf ("%s", str);
		n = strlen (str);
		node nd;
		nd.l = 0;
		nd.r = 0;
		curr = '\0';
		for (ll i = 0; i < n; ++i) {
			if (curr == '\0') {
				nd.l = i;
				nd.r = i;
				curr = str[i];
			}
			else if (curr == str[i]) {
				nd.r = i;
			}
			else {
				arr.push_back (nd);
				curr = '\0';
				i--;
			}
		}
		arr.push_back (nd);
		cnt = 0;
		for (ll i = 0; i < arr.size(); ++i) {
			ll temp = arr[i].r - arr[i].l + 1;
			cnt += ((temp - 1) * (temp)) / 2;
			if (arr[i].l > 0 && arr[i].r < n && str[arr[i].l - 1] == str[arr[i].r + 1]) {
				cnt++;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}