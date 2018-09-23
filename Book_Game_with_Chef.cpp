#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		string str = to_string(N);
		int arr[10];
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < str.size(); i++)
		{
			arr[str[i] - 48]++;
		}
		ll sum = 0;
		for(int i = 0; i < 10; i++)
		{
			sum += arr[i];
		}
		cout << (sum) << "/" << (10 * N) << "\n";
	}
	return 0;
}
//Book_Game_with_Chef.cpp