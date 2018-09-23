#include<iostream>
using namespace std;
#define MOD 1000000007
void multiply(long long int F[2][2], long long int M[2][2]);
void power(long long int F[2][2], long long int n);
void power(long long int arr[2][2],long long int n)
{
	if(n==0 || n==1)
	{
		return;
	}
	long long int M[2][2]={{1,1},{1,0}};
	power(arr,n/2);
	multiply(arr,arr);
	if(n%2!=0)
	{
		multiply(arr,M);
	}
	
}
void multiply(long long int F[2][2],long long int M[2][2])
{
	long long int x=(F[0][0]*M[0][0]+F[0][1]*M[1][0])%MOD;
	long long int y=(F[0][0]*M[0][1]+F[0][1]*M[1][1])%MOD;
	long long int z=(F[1][0]*M[0][0]+F[1][1]*M[1][0])%MOD;
	long long int w=(F[1][0]*M[0][1]+F[1][1]*M[1][1])%MOD;
	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
}
int main()
{
	int T,i,j,k;
	cin>>T;
	while(T--)
	{
		long long int N;
		cin>>N;
		long long int arr[2][2]={{1,1},{1,0}};
		power(arr,N-1);
		cout<<arr[0][0]<<endl;
		
	}
}