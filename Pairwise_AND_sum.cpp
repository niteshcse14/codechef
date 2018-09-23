#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const MAX = 1e5 + 10;
ll arr[MAX][32];
int main()
{
	memset(arr, 0, sizeof(arr));
	ll N, data;
	scanf("%lld", &N);
	ll array[N], ans = 0;
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &array[i]);
	}
	ll sum = 0;
	for(int i = 0; i < 32; i++)
	{
		ll set_bit = 0;
		for(int j = 0; j < N; j++)
		{
			if(((1 << i) & array[j]))
			{
				set_bit++;
			}
		}
		ans = ((set_bit) * ((set_bit) - 1) / (2)) * (1 << i);
		printf("%d    %d    %d\n", i, set_bit, ans);
		sum += ans;
	}
	printf("%lld\n", sum);
	/*
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &data);
		for(int j = 0; j < 32; j++)
		{
			arr[i][j] += arr[i - 1][j] + ((data >> j) & 1);
		}
	}
	unsigned long long sum = 0;
	int ans;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j < 32; j++)
		{
			ans = arr[i][j] - arr[i - 1][j];
			if(ans)
			{
				sum += arr[i - 1][j] * (1 << j);
			}
		}
	}
	*/
	//printf("%lld\n", sum);
	return 0;
}