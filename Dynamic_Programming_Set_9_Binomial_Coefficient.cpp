#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	int arr[100][100];
	for(int i = 0; i < 100; i++)
	{
		for(int j = i; j < 100; j++)
		{
			if(i == 0 || i == j)
			{
				arr[i][j] = arr[j][i] = 1;
			}
			else
			{
				arr[i][j] = arr[j][i] = arr[i - 1][j - 1] + arr[i][j - 1];
			}
			cout << arr[i][j] << " ";
		}
		printf("\n");
	}
	cin >> T;
	while(T--)
	{
		cin >> N;
	}
	return 0;
}