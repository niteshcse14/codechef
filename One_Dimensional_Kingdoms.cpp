#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n;
int a[maxn];
int b[maxn];
int visited[maxn];
struct query {
	int start;
	int end;
};
query qu[maxn];
bool cmp(const query &_a, const query &_b) {
	return _a.end < _b.end;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int l = 9999999;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &qu[i].start, &qu[i].end);
			if (qu[i].start < l) {
				l = qu[i].start;
			}
		}
		l--;
		sort(qu, qu + n, cmp);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (qu[i].start > l) {
				l = qu[i].end;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}