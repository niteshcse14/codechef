#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, p, cnt1, cnt2, data, div_two, div_ten;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		cnt1 = cnt2 = 0;
		scanf ("%lld%lld", &n, &p);
		div_two = p / 2;
		div_ten = p / 10;
		for (ll i = 0; i < n; ++i) {
			scanf ("%lld", &data);
			if (data <= div_ten) {
				cnt1++;
			}
			else if (data >= div_two) {
				cnt2++;
			}
		}
		if (cnt1 == 2 && cnt2 == 1) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}