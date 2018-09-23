#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int t, n, m, cnt;
int inp[maxn][maxn], ans[maxn][maxn];
bool cols[maxn], rows[maxn];
char str[maxn];
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(cols, false, sizeof cols);
		memset(rows, false, sizeof rows);
		cnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0 ; i < maxn; ++i)
			for (int j = 0; j < maxn; ++j)
				ans[i][j] = INT_MAX;
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			for (int j = 0; j < m; ++j) {
				inp[i][j] = str[j] - '0';
				if (inp[i][j] == 1) {
					ans[i][j] = 0;
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			for (int i = 0; i < n; ++i) {
				//if (rows[i] == 0) continue;
				for (int j = 0; j < m; ++j) {
					printf("-1 ");
				}
				printf("\n");
			}
			//printf("\n");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (inp[i][j] == 1) {
					rows[i] = true;
					cols[j] = true;
				}
			}
		}
		/*
		for (int j = 0; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				if (inp[i][j] == 1)
					cols[j] = true;
			}
		}
		*/
		for (int i = 0; i < n; ++i) {
			if (rows[i] == 0) continue;
			for (int j = 0; j < m; ++j) {
				if (ans[i][j] == INT_MAX)
					ans[i][j] = 1;
			}
		}
		for (int j = 0; j < m; ++j) {
			if (cols[j] == 0) continue;
			for (int i = 0; i < n; ++i) {
				if (ans[i][j] == INT_MAX)
					ans[i][j] = 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (ans[i][j] == INT_MAX) printf("2 ");
				else printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
		//printf("\n");
	} 
	return 0;
}