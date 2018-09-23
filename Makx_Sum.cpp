#include<iostream>
#include<set>
#include<math.h>
#include<stdlib.h>
#define ll long long int
using namespace std;
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		int N,K1,K2,K3,i,j,k,sum=0;
		int I=0;
		cin>>N>>K1>>K2>>K3;
		int size=(N*(N+1))/2;
		int arr[N]={0},ans[size]={0};
		for(i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<N;i++)
		{
			for(j=i;j<N;j++)
			{
				sum=0;
				for(k=i;k<=j;k++)
				{
					//cout<<arr[k]<<" ";
					sum+=arr[k];
				}
				//cout<<endl;
				ans[I]=sum;
				I++;
			}
		}
		multiset<int> m(ans,ans+I);
		multiset<int>::iterator it=m.end();
		while(it!=m.begin())
		{
			--it;
			if(it==(K1-1))
			{
				cout<<(*it)<<" ";
			}
			else if(it==(K2-1))
			{
				cout<<(*it)<<" ";
			}
			else if(it==(K3-1))
			{
				cout<<(*it)<<endl;
				break;
			}
		}
	}
}