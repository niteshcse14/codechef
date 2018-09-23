#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int N, i, j;
	cin>>N;
	int arr[N][N] = { 0 };
	int count_one = 0, MN = 0;
	for(i = 0;i < N; i++)
	{
		for(j = 0;j < N; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j] == 1)
			{
				count_one++;
			}
			if(MN < abs(i - j))
			{
				MN = abs(i - j);
			}
		}
	}
	int sum = N;
	if(count_one <= sum)
	{
		cout<<"0\n";
	}
	else
	{
		for(i = 1; i < N; i++)
		{
			sum += 2 * (N - i);
			if(count_one <= sum)
			{
				cout<<i<<"\n";
				break;
			}
		}
	}
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	solve();
    }
    return 0;
}
//Matrix_Bandwidth.cpp