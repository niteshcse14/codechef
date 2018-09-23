#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef pair<int, pair<int, int> > iPair;
int main()
{
	ll T, N, D, d, t, s, sum, days;
	scanf("%lld", &T);
	while(T--)
	{
		sum = 0;
		scanf("%lld %lld", &N, &D);
		int arr[D + 1];
		vector<iPair> vect;
		for(int i = 1; i <= N; i++)
		{
			scanf("%lld %lld %lld", &d, &t, &s);
			vect.push_back(make_pair(s, make_pair(d, t)));
		}
		memset(arr, 0, sizeof(arr));
		int count = 0;
		sort(vect.begin(), vect.end());
		int SS = vect.size() - 1;
		for(int i = SS; i >= 0; i--)
		{
			int second_first = vect[i].second.first;
			t = vect[i].second.second;
			int vect_first = vect[i].first;
			//printf("%d  %d  %d %lld\n", vect_first, second_first, t, sum);
			if(count == D)
			{
				sum += vect_first * t;
				continue;
			}
			for(int j = second_first; j <= D && t > 0; j++)
			{
				if(arr[j] == 0)
				{
					arr[j] = 1;
					t--;
					count++;
				}
			}
			sum += vect_first * t;
			//printf("%d  %d  %d %lld\n\n", vect_first, second_first, t, sum);
		}
		printf("%lld\n", sum);
	}
	return 0;
}