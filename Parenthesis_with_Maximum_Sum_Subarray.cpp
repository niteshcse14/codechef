#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
int arr[maxn];
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
	}
	return 0;
}