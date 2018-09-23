#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int arr[maxn];
int t, n, data, idx, idxk;
int ans[10];
int flag;
int dp[10][10];
int visited[10];
int main () {
	scanf ("%d", &t);
	while (t--) {
		memset (ans, 0, sizeof(ans));
		memset (visited, 0, sizeof(visited));
		memset (dp, 0, sizeof(dp));
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", &arr[i]);
		}
		for (int i = 1; i <= 6; ++i) {
			dp[i][i] = 1;
		}
		flag = 0;
		for (int i = 2; i <= n; ++i) {
			if (arr[i] == arr[i - 1]) {
				flag = 1;
				break;
			}
			dp[arr[i]][arr[i - 1]] = 1;
			dp[arr[i - 1]][arr[i]] = 1;
		}
		if (flag == 1) {
			printf("-1\n");
			continue;
		}
		//printf("Hello\n");
		for (int i = 1; i <= 6 && !flag; ++i) {
			if (dp[1][i] == 1) {
				continue;
			}
			//printf("%d\n", i);
			ans[1] = i;
			ans[i] = 1;
			visited[1] = visited[i] = 1;
			for (int j = 1; j <= 6 && !flag; ++j) {
				idx = -1;
				for (int m = 1; m <= 6; ++m) {
					if (visited[m] == 0 && dp[j][m] == 0 && visited[j] == 0) {
						idx = m;
						break;
					}
				}
				if (idx == -1) {
					continue;
				}
				//printf("j %d  %d\n", j, idx);
				ans[idx] = j;
				ans[j] = idx;
				visited[idx] = visited[j] = 1;
				for (int k = 1; k <= 6 && !flag; ++k) {
					idxk = -1;
					for (int m = 1; m <= 6; ++m) {
						if (visited[m] == 0 && dp[k][m] == 0 && visited[k] == 0) {
							idxk = m;
							break;
						}
					}
					if (idxk == -1) {
						continue;
					}
					ans[idxk] = k;
					ans[k] = idxk;
					flag = true;
					visited[idxk] = visited[k] = 1;
				}
				if (flag == false) {
					visited[j] = visited[idx] = 0;
				}
			}
			if (flag == false) {
				visited[i] = visited[1] = 0;
			}
		}
		if (flag) {
			for (int i = 1; i <= 6; ++i) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}