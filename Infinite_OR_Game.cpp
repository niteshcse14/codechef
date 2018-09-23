#include <bits/stdc++.h>
using namespace std;
int const N = 20;
int const maxn = (1 << N) + 5;
int arr[maxn];
int cnt[maxn];
int t, n, k, ans;
int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			cnt[arr[i]] = 1;
		}
		for (int i = 0; i < k; ++i) {
			if (cnt[1 << i] == 0) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}