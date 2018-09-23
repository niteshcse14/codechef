#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll N,i,j,sum=0,k,l;
		cin>>N;
		ll arr[N];
		for (i = 0; i < N; ++i)
		{
			cin>>arr[i];
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				for(k=i+1;k<N;k++)
				{
					if(arr[k]==arr[i] || arr[k]==arr[j])
					{
						continue;
					}
					for(l=;l<N;l++)
					{
						if(arr[l]==arr[i] || arr[l]==arr[j])
						{
							continue;
						}
						else
						{
							cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[l]<<endl;
							sum++;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
}