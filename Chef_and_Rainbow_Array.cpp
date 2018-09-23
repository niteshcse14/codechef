#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, data;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		int arr[N], mx = INT_MIN;
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		int seven[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		bool flag = true;
		int end;
		if(N % 2 == 0)
		{
			end = N / 2;
		}
		else
		{
			end = N / 2 + 1;
		}
		for(int i = 0; i < end; i++)
		{
			seven[arr[i]]++;
			if(arr[i] != arr[N - i - 1])
			{
				flag = false;
				break;
			}
		}
		for(int i = 1; i <= 7; i++)
		{
			if(seven[i] == 0)
			{
				flag = false;
			}
		}
		if(flag)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}