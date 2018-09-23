#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define iPair pair <int, int>
#define maxn 10005
int t, n, a, b, pt_a, pt_b, pt_c, pt_d;
int inp[maxn][maxn], res_a[maxn], res_b[maxn];
vector <iPair> a_pair, b_pair;
int main() {
	scanf("%d", &t);
	assert(t >= 1 and t <= 5);
	while (t--) {
		a_pair.clear();
		b_pair.clear();
		memset(inp, 0, sizeof inp);
		scanf("%d%d%d", &n, &a, &b);
		assert(n >= 1 and n <= 1000);
		assert(a >= 0 and a <= n);
		assert(b >= 0 and b <= n);
		assert(a + b >= 0 and a + b <= n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &inp[i][j]);
				assert(inp[i][j] >= 0 and inp[i][j] <= 1);
				//assert(inp[i][j] + inp[j][i] == 1);
				if (i == j)
					assert(inp[i][j] == 0);
			}
		}
		pt_a = pt_b = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (inp[i][j] && a_pair.empty()) {
					//printf("a %d %d\n", i, j);
					res_a[i]++;
					pt_a = i + 1;
					a_pair.pb({i + 1, j + 1});
				}
				else if (!inp[i][j] && b_pair.empty() && pt_a != (i + 1)) {
					//printf("b %d %d\n", i, j);
					res_b[j]++;
					pt_b = i + 1;
					b_pair.pb({i + 1, j + 1});
				}
			}
		}
		/*
		for (int i = 0; i < n; ++i) {
			if (i + 1 == pt_a) 
				printf("%d ", n);
			else
				printf("0 ");
		}
		printf("\n");
		for (int i = 0; i < n; ++i) {
			if (i + 1 == pt_b) 
				printf("%d ", n);
			else
				printf("0 ");
		}
		printf("\n");
		*/
		printf("%d\n", n);
		/*
		for (int i = 0; i < a; ++i)
			printf("%d %d\n", pt_a, pt_b);
		for (int i = 0; i < b; ++i)
			printf("%d %d\n", pt_a, pt_b);
		*/
	}
	return 0;
}