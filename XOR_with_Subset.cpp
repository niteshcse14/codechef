#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1025
ll dp[MAX][MAX];
ll arr[1025];
int main()
{
	ll T,  N, K;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld %lld", &N, &K);
		ll arr[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &arr[i]);
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 0; j < 1024; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ arr[i - 1]];
			}
		}
		/*
		for(int i = 1; i <= N; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				printf("%lld  ", dp[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		ll mx = INT_MIN;
		for(int i = 0; i < 1024; i++)
		{
			if(dp[N][i])
			{
				mx = max(mx, i ^ K);
			}
		}
		printf("%lld\n", mx);
	}
	return 0;
}