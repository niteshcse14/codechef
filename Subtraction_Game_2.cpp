#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int ,int > PII;
map < PII, ll> present;
ll arr[110];
ll N, T;
ll gcd(ll a,ll b){
    if(b > a) 
    	return gcd(b,a);
    return b == 0 ? a : gcd(b, a % b);
}
ll sequence(ll pos, ll curr_gcd){
	if(pos == N){
		if(curr_gcd == 1){
			return 1;
		}
		else{
			return 0;
		}
	}
	PII key = make_pair(pos, curr_gcd);
	if(present.find(key) != present.end()){
		return present[key];
	}
	return present[key] = sequence(pos + 1, curr_gcd) + sequence(pos + 1, gcd(curr_gcd, arr[pos]));
}
int main(){
	scanf("%lld", &T);
	while(T--){
		scanf("%lld", &N);
		for(ll i = 0; i < N; ++i){
			scanf("%lld", &arr[i]);
		}
		present.clear();
		ll res = 0;
		for(int i = 0; i < N; ++i){
			res += sequence(i + 1, arr[i]);
		}
		printf("%lld\n", res);
	}
	return 0;
}