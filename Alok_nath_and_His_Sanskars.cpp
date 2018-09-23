#include <bits/stdc++.h>
using namespace std;
#define ll long long
int recur(ll arr[], ll N, ll x)
{
	if(x == 0)
	{
		return 1;
	}
	if(N == -1)
	{
		return 0;
	}
	if(arr[N] < 0 || arr[N] > x)
	{
		return recur(arr, N - 1, x);
	}
	if(recur(arr, N - 1, x - arr[N]))
	{
		arr[N] = -1;
		return 1;
	}
	return recur(arr, N - 1, x);
}
int main()
{
	ll T, N, K, count;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld", &N, &K);
		long long arr[25];
		ll sum = 0;
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &arr[i]);
			sum += arr[i];
		}
		if(sum % K != 0 || K > N)
		{
			printf("no\n");
		}
		else
		{
			ll x = sum / K;
			count = 0;
			for(int i = 0; i <  K; i++)
			{
				if(recur(arr, N - 1, x))
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if(count == K)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		/*
		if(sum == 0)
		{
			if(N >= K)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
			continue;
		}
		if(sum % K != 0)
		{
			printf("no\n");
			continue;
		}
		count = 0;
		ll div =1LL * sum / K;
		for(ll i = 0; i < (ll)(pow(2, N)); i++)
		{
			sum = 0;
			for(int j = 0; j < N; j++)
			{
				if((i & (1LL << j)) && arr[j] > 0)
				{
					sum += 1LL * arr[j];
				}
			}
			if(sum == div)
			{
				for(int j = 0; j < N; j++)
				{
					if(i & (1LL << j))
					{
						arr[j] = -1;
					}
				}
				count++;
			}
		}
		if(count == K)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
		*/
	}
	return 0;
}