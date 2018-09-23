#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long int MOD = (ll)(1e9 + 7);
ll isPrime[5000001];
ll ans[5000001];
ll primes[5000001];
ll T, N;
void init()
{
	for(ll i = 4; i < 5000001; i += 2)
	{
		isPrime[i] = 1;
	}
	for(ll i = 3; (i * i) < 5000001; i += 2)
	{
		if(isPrime[i] == 0)
		{
			for(ll j = i * i; j < 5000001; j += i)
			{
				isPrime[j] = 1;
			}
		}
	}
	for(ll i = 1; i < 5000001; i++)
	{
		if(isPrime[i] != 0)
		{
			primes[i] = primes[i - 1];
		}
		else
		{
			primes[i] = primes[i - 1] + 1;
		}
	}
	ans[1] = 1;
	for(ll i = 2; i < 5000001; i++)
	{
		ans[i] = (ans[i - 1] * primes[i]) % 1000000007;
	}
}
int main()
{
	init();
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &N);
		printf("%lld\n", ans[N]);
	}
	return 0;
}