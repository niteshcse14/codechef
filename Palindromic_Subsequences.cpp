#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	string str;
	cin >> T;
	while(T--)
	{
		cin >> str;
		int N = str.length();
		int dp[N + 1][N + 1];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < N; i++)
		{
			dp[i][i] = 1;
		}
		for(int i = 2; i <= N; i++)
		{
			for(int j = 0; j < N - i + 1; j++)
			{
				int k = i + j - 1;
				if(str[j] == str[k])
				{
					dp[j][k] = dp[j + 1][k] + dp[j][k - 1] + 1;
				}
				else
				{
					dp[j][k] = dp[j + 1][k] + dp[j][k - 1] - dp[j + 1][k - 1];
				}
			}
		}
		printf("%d\n", dp[0][N - 1]);
	}
	return 0;
}