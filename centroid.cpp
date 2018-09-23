#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, B;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &B);
		if(B == 0)
		{
			if(N == 2)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
				for(int i = 1; i < N; i++)
				{
					printf("%d %d\n", 1, i + 1);
				}
			}
		}
		else if(N == 2 && B == 1)
		{
			printf("YES\n");
			printf("1 2\n");
		}
		else if(4 * B > N)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			printf("YES\n");
			for(int i = 0; i < 2 * B; i++)
			{
				printf("%d %d\n", i + 1, i + 2);
			}
			for(int i = 2 * B + 1; i < N; i++)
			{
				printf("%d %d\n", 2 * B + 1, i + 1);
			}
		}
	}
	return 0;
}