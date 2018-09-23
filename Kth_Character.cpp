#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
ull M = 1152921504606846976;
int kTh_char(ull k, ull low, ull max, int flag){
	if(low <= max){
		ull mid = (low + max) / 2;
		if(mid == k){
			return flag;
		}
		else if(k > mid){
			return kTh_char(k, mid + 1, max, 1);
		}
		else{
			return kTh_char(k, low, mid - 1, 0);
		}
	}
}
int main(){
	ull T, N;
	scanf("%llu", &T);
	while(T--){
		scanf("%llu", &N);
		printf("%c\n", (kTh_char(N - 1, 0, M, 0) == 0) ? 'a' : 'c');
	}
	return 0;
}