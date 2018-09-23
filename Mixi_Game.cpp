#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
int t, n, k, sum_a, sum_b, sum;
int inp[maxn];
int main() {
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		sum_a = sum_b = 0;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &inp[i]);
			if (i & 1) {
				if (sum > 0) sum += inp[i];
				else sum -= inp[i];
			}
			else {
				if (sum > 0) sum -= inp[i];
				else sum += inp[i];
			}
		}
		if (abs(sum) >= k) printf("1\n");
		else printf("2\n");
	}
	return 0;
}