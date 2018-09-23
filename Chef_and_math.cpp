#include<iostream>
using namespace std;
# define ll long long int
int chef_num(ll n,ll chef[])
{
	int flag=1;
	for(int i=0;;i++)
	{
		if(chef[i]>n)
		{
			flag=0;
			break;
		}
		else if(chef[i]==n)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
int main()
{
	ll chef[]={1,2,3,5,8,13,21,34,55,89,144,223,377,600,977,1577,2554,4131,6685,10816,17501,28317,45818,74135,119953,194088,314041,508129,822170,1330299,2152469,3482768,5635237,9118005,14753242,23871247,38624489,62495736};
	cout<<sizeof(chef)<<endl;
	ll Q,X,K;
	cin>>Q;
	while(Q--)
	{
		cin>>X>>K;
		if(chef_num(X,chef)==0)
		{
			cout<<"0"<<endl;
		}
		else if(K==1)
		{
			cout<<"1"<<endl;
		}
		else
		{
			ll sum=0;
			if(K<=4)
			{
				for(int i=0;i<35;i++)
				{
					if((chef[i])>X)
					{
						break;
					}
					for(int j=i;j<35;j++)
					{
						if((chef[i]+chef[j])>X)
						{
							continue;
						}
						for(int k=j;k<35;k++)
						{
							if((chef[i]+chef[j]+chef[k])>X)
							{
								continue;
							}
							for(int l=k;l<35;l++)
							{
								if((chef[i]+chef[j]+chef[k]+chef[l])>X)
								{
									break;
								}
								//cout<<chef[i]<<" "<<chef[j]<<" "<<chef[k]<<" "<<chef[l]<<endl;
								if((chef[i]+chef[j]+chef[k]+chef[l])==X)
								{
									sum++;
								}
							}
						}
					}
				}
				cout<<sum<<endl;
			}
		}
	}
}