#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll T, last, greater, less, ans;
	string str;
	scanf("%lld", &T);
	while(T--)
	{
		cin >> str;
		greater = less = ans =  0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '<')
			{
				greater++;
				less = 0;
			}
			else if(str[i] == '>')
			{
				less++;
				greater = 0;
			}
			ans = max(ans, max(greater, less));
		}
		printf("%lld\n", ans + 1);
	}
	return 0;
}
