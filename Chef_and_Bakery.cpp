#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int T;
    cin>>T;
    while(T--)
    {
    	long long int N,X;
    	cin>>N>>X;
    	long long int ans = N % X;
    	if(ans != 0)
    	{
    		cout<<ans<<endl;
    	}
    	else
    	{
    		cout<<(X)<<endl;
    	}
    }
    return 0;
}
//Chef_and_Bakery.cpp
//99999999999999999 99999999999999991