#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
ull solve(ull N, ull K){
	if(N == 1){
		return K;
	}
	N >>= 1;
	if(K & 1){
		return (N + solve(N, K / 2));
	}
	else{
		return (solve(N, K / 2));
	}
}
int main(){
	ull N, K, T;
	scanf("%llu", &T);
	while(T--){
		scanf("%llu%llu", &N, &K);
		if(N < 64){

			printf("%llu\n", solve(1ULL << N, K));
		}
		else{
			if(K & 1){
				printf("%llu\n", (solve((1ULL << (N - 1)), K / 2) + (1ULL << (N - 1))));
			}
			else{
				printf("%llu\n", solve((1ULL << (N - 1)), K >> 1));
			}
		}
	}
	return 0;
}