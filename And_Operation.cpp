#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN = 300005;
const ll MAXN_a = 1000001;
ll N, cnt, ANS;
ll arr[MAXN];
ll flag[MAXN];
int main(){
	scanf("%lld", &N);
	for(ll i = 0; i < N; ++i){
		scanf("%lld", &arr[i]);
	}
	for(int i = 31; i >= 0; --i){
		cnt = 0;
		for(int j = 0; j < N; ++j){
			if(!flag[j] && arr[j] & (1 << i)){
				cnt++;
			}
		}
		if(cnt <= 1){
			continue;
		}
		if(cnt > 1){
			ANS += 1 << i;
		}
		for(int j = 0; j < N; ++j){
			if(!flag[j] && !(arr[j] & (1 << i))){
				flag[j] = 1;
			}
		}
	}
	printf("%lld\n", ANS);
	return 0;
}