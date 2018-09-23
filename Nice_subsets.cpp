#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll N,K,A,B,i,j,k=0;
	cin>>N>>K>>A>>B;
	int arr[N]={0};
	for (i = 0; i < N; ++i)
	{
		cin>>arr[i];
	}
	
	for(i=0;i<N;i++)
	{
		ll f[arr[i]+1]={0};
		for(j=2;j<=arr[i]/2;)
		{
			if(arr[i]%j==0)
			{
				f[j]+=1;
				//cout<<j<<" i "<<i<<endl;
				k++;
				arr[i]/=j;
			}
			else
			{
				j++;
			}
		}
		f[arr[i]]+=1;
		k++;
		int kk=2;
		int ans=1;
		while(true)
		{
			if(f[kk]!=0)
			{
				if(ans*f[kk]==arr[i])
				{
					sum+f[kk];
					return;
				}
			}
			k++;
		}
	}
	cout<<"k"<<k<<endl;
	for(i=1;i<=k;i++)
	{
		cout<<f[i]<<" ";
	}
	cout<<endl;
}