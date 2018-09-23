#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, a, b, n, j, a_cnt, b_cnt;
char str[maxn];
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s%d%d", str, &a, &b);
		n = strlen (str);
		for (int i = 0; i < n; ++i) {
			if (str[i] == 'a') a_ch++;
			else b_ch++;
		}
		j = a_cnt = b_cnt = 0;
		while (j < n) {
			if (a_cnt == a) {
				if (b_ch > 0) {
					printf("b");
					b_ch--;
					b_cnt++;
					a_cnt = 0;
					j++;
				}
				else printf("*");
			}
			else if (a_ch > 0) {
				printf("a");
				a_ch--;
				a_cnt++;
				b_cnt = 0;
				j++;
			}
			else if (b_cnt == b) {
				if (a_ch > 0) {
					printf("a");
					a_cnt++;
					b_cnt = 0;
					a_ch--;
				}
				else printf("*");
			}
			else if (b_ch > 0) {
				printf("b");
				b_cnt++;
				a_cnt = 0;
				b_ch--;
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}