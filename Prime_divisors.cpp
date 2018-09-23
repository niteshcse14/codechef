#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
int t, n, temp, sum, sum1, res;
int pm[maxn], inp[maxn];
void seive() {
	for (int i = 1; i < maxn; ++i)
		pm[i] = i;
	for (int i = 2; i * i < maxn; ++i) {
		for (int j = 2 * i; j < n; j += i) 
			pm[j] = i;
	}
}
int main() {
	seive();
	scanf("%d", &t);
	while (t--) {
		res = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &inp[i]);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				sum = sum1 = 0;
				temp = inp[i];
				while (temp > 1) {
					sum += pm[temp];
					while (temp % pm[temp] == 0 && temp > 1) { 
						temp /= pm[temp];
						//printf("IN\n");
					}
				}
				temp = inp[j];
				while (temp > 1) {
					sum1 += pm[temp];
					while (temp % pm[temp] == 0 && temp > 1) 
						temp /= pm[temp];
				}
				if (sum1 % sum == 0) {
					res++;
					printf("%d %d %d %d\n", i + 1, j + 1, sum1, sum);
				}
			}
		}
		printf("%d\n", res);
	} 
	return 0;
}