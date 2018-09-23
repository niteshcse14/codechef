#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll n,m,p,a,b,P=0,i,j,sum=0,flag=0;
	cin>>n>>m>>p;
	ll arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			arr[i][j]=j;;
		}
	}
	P=p;
	while(p--)
	{
		cin>>a>>b;
		arr[a-1][b-1]+=1;
	}
	i=0;

	//int dif=0;
	while(i!=(n-1))
	{
		sum=0;
		flag=0;
		for(j=m-1;j>0;j--)
		{
			int dif=arr[i][j]-arr[i][j-1];
			if(dif<0)
			{
				flag=0;
				break;
			}
			else
			{
				sum+=dif;
				flag=1;
			}
		}
		if(flag==1)
		{
			cout<<(sum+1)<<endl;
		}
		else
		{
			cout<<"-1"<<endl;
		}
		i++;
	}
}