#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll T, N, curr;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &N);
		ll ans = 0, pre = -1, count = 0;
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &curr);
			if(i == 0)
			{
				count = 1;
			}
			else 
			{
				if(curr >= pre)
				{
					++count;
				}
				else
				{
					count = 1;
				}
			}
			//printf("%d   %d   ", pre, curr);
			ans += count;
			pre = curr;
			//printf("%d  %d\n", count, ans);
		}
		/*
		ll count = 0;
		for(int i = 0; i < N; i++)
		{
			count++;
			if(i != N - 1 && arr[i] > arr[i + 1])
			{
				ans += count * (count - 1) / 2;
				count = 0;
			}
		}
		ans += count * (count - 1) / 2;
		*/
		printf("%lld\n", ans);
	}
	return 0;
}