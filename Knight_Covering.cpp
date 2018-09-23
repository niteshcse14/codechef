#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, M, mul;
	cin >> T;
	//int row[] = [2, 1, -1, -2, -2, -1, 1, 2];
	//int cols[] = [1, 2, 2, 1, -1, -2, -2, -1];
	while(T--)
	{
		cin >> N >> M;
		if(N == 1 || M == 1 || M == 2)
		{
			cout << M * N << "\n";
			continue;
		}
		int arr[N][M];
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				arr[i][j] = 0;
			}
		}
		int sum = 0;
		for(int i = 0; i < M; i++)
		{
			for(int j = 2; j < N; j += 2)
			{
				if(arr[j][i] == 0)
				{
					sum++;
				}
				if((i + 2) < N && (j + 1) < M)
				{
					arr[i + 2][j + 1] = 1;
				}
				if((i + 1) < N && (j + 2) < M)
				{
					arr[i + 1][j + 2] = 1;
				}
				if((i  - 1) <= 0 && (j + 2) < M)
				{
					arr[i - 1][j + 2] = 1;
				}
				if((i - 2) >= 0 && (j + 1) < M)
				{
					arr[i - 2][j + 1] = 1;
				}
				if((i - 2) >= 0 && (j - 1) >= 0)
				{
					arr[i - 2][j - 1] = 1;
				}
				if((i - 1) >= 0 && (j - 2) >= 0)
				{
					arr[i - 1][j - 2] = 1;
				}
				if((i + 1) < N && (j - 2) >= 0)
				{
					arr[i + 1][j - 2] = 1;
				}
				if((i + 2) < N && (j - 1) >= 0)
				{
					arr[i + 2][j - 1] = 1;
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}