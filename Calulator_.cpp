#include <bits/stdc++.h>
#include <stdafx.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
#define ll long long int
int main()
{
	ll T, N, B, n, result;
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &N);
		for(ll cas = 1; cas < N / 2; cas++)
		{
			B = cas;
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
			if(B == 1)
			result = pow(N / 2, 2);
			ll ans = INT_MIN;
			if(N % 2 != 0)
			{
				result += N / 2;
			}
			ll ANS = 0, index;
			for(ll i = 1; i <= (N - B); i++)
			{
				ans = i * ((N - i) / B);
				if(ans > ANS)
				{
					ANS = ans;
					index = i;
				}
			}
			 SetConsoleTextAttribute(console, 240);
			printf("%4lld  %4lld  %4lld  %4lld\n", B, ANS, result / B, index);
		}
	}
	return 0;
}