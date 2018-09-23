#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T, N, Q, count, last, flag = 1, K, back, i;
	cin >> T;
	while(T--)
	{
		cin >> N >> Q;
		vector<int> arr(N, 0);
		for(i = 0;i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end(), greater<int>());
		/*
		for(i = 0;i < N; i++)
		{
			cout << arr[i] << " ";
		}
		printf("\n");
		*/
		while(Q--)
		{
			back = 0;
			count = 0;
			last = 0;
			flag = 1;
			bool visited[N];
			for(i = 0; i < N; i++)
			{
				visited[i] = true;
			}
			cin >> K;
			while(visited[count] != false)
			{
				for(i = count; i < (N - back) && visited[i] != false; i++)
				{
					//cout << K << " " << back << " " << count << " " << arr[i] << " ";
					if(visited[i] == false)
					{
						//cout << " true1\n";
						flag = 0;
						break;
					}
					else if(arr[i] >= K)
					{
						//cout << " true2\n";
						count++;
					}
					else
					{
						int temp = K - arr[i];
						if(temp > (N - count - back - 1))
						{
							//cout << temp << " true3\n";
							flag = 0;
							break;
						}
						else if(temp == (N - count - back - 1))
						{
							//cout << temp << " true4\n";
							count++;
							flag = 0;
							break;
						}
						else if(temp < (N - count - back - 1))
						{
							//cout << temp << " true5\n";
							back += temp;
							visited[N - back] = false;
							count++;
						}
					}
				}
				if(flag == 0 || count == N || visited[i] == false)
				{
					break;
				}
			}
			cout << count << "\n";
		}
	}
} 