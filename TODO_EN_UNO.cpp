#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN = 1000005;
ll cnt[MAXN];
ll ANS, N, T, data, heigh;
ll max_pair(){
	for(ll i = heigh; i >= 1; --i){
		ANS = 0;
		for(ll j = i; j <= heigh; j += i){
			if(cnt[j]){
				ANS += cnt[j];
				if(ANS >= 2){
					return i;
				}
			}
		}
	}
}
int main(){
	scanf("%lld", &T);
	while(T--){
		memset(cnt, 0, sizeof(cnt));
		scanf("%lld", &N);
		heigh = 0;
		for(ll i = 1; i <= N; ++i){
			scanf("%lld", &data);
			heigh = max(heigh, data);
			cnt[data]++;
		}
		printf("%lld\n", max_pair());
	}
	return 0;
}