#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#define ll long long int
using namespace std;
int main()
{
	ll N,K,i,j;
	cin>>N>>K;
	ll size=(N*(N+1))/2;
	ll arr[N+1]={0};
	vector<ll> ans;
	for(i=1;i<=N;i++)
	{
		cin>>arr[i];
	}
	for(i=1;i<=N;i++)
	{
		ll sum=0;
		for(j=i;j<=N;j++)
		{
			sum+=arr[j];
			ans.push_back(sum);
		}
	}
	sort(ans.rbegin(),ans.rend());
	for(i=0;i<K;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}