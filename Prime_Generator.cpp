#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, M, T, ans;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		scanf("%d %d", &N, &M);
		for(int i = N; i <= M; i++)
		{
			if(i == 1)
			{
				continue;
			}
			bool flag = true;
			for(int j = 2; j * j <= i; j++)
			{
				if(i % j == 0)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}