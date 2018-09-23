#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		t = N;
		cout << N << "\n";
		for(int t = 1; t <= N; t++)
		{
			cout << N << "\n";
			for(int i = 1; i <= N; i++)
			{
				cout << i << " " << t << " ";
				if((t + 1) % 2 == 0)
				{
					cout << "1\n";
				}
				else
				{
					cout << (t + 1) << "\n";
				}
			}
		}
	}
	return 0;
}