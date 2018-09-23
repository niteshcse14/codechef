#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 1e6 + 3;
int fac[MOD + 1], inv[MOD + 1];
int pow(int n, int r){
	if(r == 0){
		return 1;
	}
	int tt = pow(n, r / 2);
	if(r % 2 == 0){
		tt = (tt * 1LL * tt) % MOD;
	}
	else{
		tt = (tt * 1LL * tt * n * 1LL) % MOD;
	}
	return tt;
}
int cal(int n, int r){
	if(r > n){
		return 0;
	}
	return ((fac[n]) * 1LL * ((inv[r] * 1LL * inv[n - r]))) % MOD;
}
/*
ll nCrDP(ll N, ll R){
	ll dp[R + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(ll i = 1; i <= N; ++i){
		for(ll j = min(i, R); j > 0; --j){
			dp[j] = (dp[j] + dp[j - 1]) % MOD;
		}
	}
	return dp[R];
}
ll nCr(ll N, ll R){
	if(R == 0){
		return 1;
	}
	ll Ni = N % MOD;
	ll Ri = R % MOD;
	return (nCr(N / MOD, R / MOD) * nCrDP(Ni, Ri)) % MOD;
}
*/
int main(){
	int T, N, K, L, R, n;
	fac[0] = 1;
	inv[0] = 1;
	for(int i = 1; i < MOD; ++i){
		fac[i] = (fac[i - 1] * 1LL * i) % MOD;
		inv[i] = pow(fac[i], MOD - 2);
	}
	//printf("%d\n", cal(1, 0));
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &n, &L, &R);
		int p = R - L + 1;
		N = n + p;
		int ans = ((cal(N / MOD, n / MOD) *  1LL * cal(N % MOD, n % MOD))) % MOD;
		if(ans == 0){
			printf("%d\n", MOD - 1);
		}
		else{
			printf("%d\n", ans - 1);
		}
	}
	return 0;
}