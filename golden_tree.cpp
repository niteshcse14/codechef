#include<iostream>
#include<math.h>
using namespace std;
#define mod 100000006
#define ll long long int
int main()
{
	ll T,i,j;
	cin>>T;
	while(T--)
	{
		ll s0,s1,s2,K,N,next_s1,c_N,next_s2;
		cin>>s0>>s1>>s2>>K>>N;
		next_s1=s0+s1;
		next_s2=(pow(2,s2))*next_s1;
		ll tax[N+next_s1+1]={0};
		tax[0]=s0;
		for(i=1;i<(1+s1);i++)
		{
			tax[i]=(tax[i-1]+1)%mod;
		}
		tax[s1+1]=2*tax[s1];
		for(i=1;i<s2;i++)
		{
			tax[s1+1+i]=(2*tax[s1+i])%mod;
		}
		if(N<=(s1+s2+1))
		{
			cout<<(tax[N-1])%mod<<endl;
		}
		else
		{
			ll ans=1,temp,I=1;
			j=s1+s2+1;
			for(j=s1+s2+1;j<N;j++)
			{
				ans=1;
				I=K+1;
				while(I-->1)
				{
					ans=(((ans)%mod)*((tax[j-I])%mod))%mod;
				}
				tax[j]=ans%mod;
			}
			cout<<(tax[N-1])%mod<<endl;
		}
	}
}