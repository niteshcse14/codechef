#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, n, ans = 0;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &n);
			ans ^= n;
		}
		if(ans == 0)
		{
			printf("Second\n");
		}
		else
		{
			printf("First\n");
		}
	}
	return 0;
}