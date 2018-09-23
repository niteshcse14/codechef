#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll N, P;
ll power(ll a, ll b)
{
	ll res = 1;
	a = a % P;
	while(b > 0)
	{
		if(b & 1)
		{
			res = (res * a) % P;
		}
		b >>= 1;
		a = (a * a) % P;
	}
	return res;
}
ll nCr(ll K)
{
	if(K == 0)
	{
		return 1;
	}
	if(K == 1)
	{
		return (N + 1) % P;
	}
	ll ans = 1;
	if(K > (N - K))
	{
		K = N - K;
	}
	for(ll i = 0; i < K; i++)
	{
		ans = ans * (N - i) % P;
		ans = (ans / (i + 1)) % P;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ll K, sum = 0;
		scanf("%lld %lld %lld", &N, &K, &P);
		ll limit = (N / K) * K;
		for(ll i = 0; i <= (N / K); i++)
		{
			sum = (sum + nCr(i * K)) % P;
		}
		printf("%lld\n", sum);
		printf("power   %lld\n", power(N / K, 2 * K));
	}
}