#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a, b, c, x, y, t;
ll inp[3];
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld%lld%lld%lld", &inp[0], &inp[1], &inp[2], &x, &y);
		sort(inp, inp + 3, greater<int>());
		a = inp[0];
		b = inp[1];
		c = inp[2];
		if (x < y) swap(x, y);
		if ((inp[0] + inp[1] + inp[2]) < (x + y)) 
			printf("NO\n");
		else if ((inp[0] + inp[1] + inp[2]) > (x + y))
			printf("NO\n");
		else {
			//printf("ELSE\n");
			if ((a + b) >= x) {
				ll temp = a + b - x;
				//printf("TEMP %lld\n", temp);
				if ((temp + c) == y) 
					printf("YES\n");
				else printf("NO\n");
			}
			else printf("NO\n");
		}
	}
	return 0;
}