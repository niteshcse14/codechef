#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int x = 0;
	x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
printf("%d\n", x);
	printf("%d\n", __builtin_popcount(7));
	ll T, N, B, n;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld", &N, &B);
		if((B > N) || (N == B))
		{
			printf("0\n");
			continue;
		}
		if(B >= (N / 2))
		{
			printf("%lld\n", N - B);
			continue;
		}
		ll res = (ll)pow(N / 2, 2), ans = INT_MIN;
		if(N % 2 != 0)
		{
			res += N / 2;
		}
		if(B == 1)
		{
			printf("%lld\n", res);
			continue;
		}
		res /= B;
		if(B % 2 == 0 && res % 2 != 0)
		{
			printf("%lld\n", res - 1);
		}
		else
		{
			printf("%lld\n", res);
		}
	}
	return 0;
}