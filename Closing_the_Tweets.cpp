#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main()
{
	int N, K, ans = 0, index;
	cin >> N >> K;
	string str;
	while(K--)
	{
		cin >> str;
		if(str == "CLICK")
		{
			cin >> index;
			if(arr[index] == 0)
			{
				ans++;
				arr[index] = 1;
			}
			else
			{
				ans--;
				arr[index] = 0;
			}
		}
		else
		{
			for(int i = 1; i <= N; i++)
			{
				arr[i] = 0;
			}
			ans = 0;
		}
		cout << ans << "\n";
	}
	return 0;
}