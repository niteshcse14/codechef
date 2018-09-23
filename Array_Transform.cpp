#include <bits/stdc++.h>
using namespace std;
int t, n, k, cnt[15], data;
bool flag;
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		flag = false;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &data);
			cnt[data % (k + 1)]++;
			if (cnt[data % (k + 1)] >= (n - 1)) {
				flag = true;
			}
		}
		if (flag) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}