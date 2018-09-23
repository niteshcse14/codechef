#include <bits/stdc++.h>
using namespace std;
int T, N;
int ceil_index(int lis[], int l, int r, int find)
{
	while((r - l) > 1)
	{
		int m = l + (r - l) / 2;
		if(lis[m] >= find)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return r;
}
int _lis(int arr[])
{
	if(N == 0)
	{
		return 0;
	}
	int j = 1, lis[N], max = -1;
	for(int i = 0; i < N; i++)
	{
		lis[i] = 0;
	}
	lis[0] = arr[0];
	for(int i = 1; i < N; i++)
	{
		if(arr[i] < lis[0])
		{
			lis[0] = arr[i];
		}
		else if(arr[i] > lis[j - 1])
		{
			lis[j++] = arr[i];
		}
		else
		{
			lis[ceil_index(lis, -1, j - 1, arr[i])] = arr[i];
		}
	}
	return j;
}
int main()
{
	//cin >> T;
	T = 1;
	while(T--)
	{
		cin >> N;
		int arr[N] ;
		for(int i = 0; i < N; i++)
		{
			cin >> arr[N - i - 1];
		}
		cout << _lis(arr) << "\n";
	}
	return 0;
}