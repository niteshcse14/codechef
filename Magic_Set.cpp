#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 1005
ll n,t,m,res,sum;
ll inp[maxn];
int main(){
	scanf("%lld",&t);
	while(t--){
		ll cnt = 0;
		scanf("%lld%lld",&n,&m);
		for(ll i=0;i<n;++i){
			scanf("%lld",&inp[i]);
			if (inp[i] % m == 0) 
				cnt++;
		}
		long long int an = 1LL * pow(2, cnt);
		printf("%lld\n", an - 1);
		//printf("%lld\n",solve(0,0));
	}
	return  0;
}