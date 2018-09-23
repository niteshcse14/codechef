#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main(){
	int N, M, P, u, v;
	scanf("%d %d %d", &M, &N, &P);
	int dp[M + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	while(P--){
		scanf("%d %d", &u, &v);
		dp[u][v] = -1;
	}
	if(dp[1][1] == -1){
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= M; ++i){
		if(dp[i][1] == 0){
			dp[i][1] = 1;
		}
		else{
			break;
		}
	}
	for(int i = 2; i <= N; ++i){
		if(dp[1][i] == 0){
			dp[1][i] = 1;
		}
		else{
			break;
		}
	}
	for(int i = 2; i <= M; ++i){
		for(int j = 2; j <= N; ++j){
			if(dp[i][j] == -1){
				continue;
			}
			if(dp[i - 1][j] > 0){
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= MOD;
			}
			if(dp[i][j - 1] > 0){
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
	for(int i = 1; i <= M; ++i){
		for(int j = 1; j <= N; ++j){
			printf("%3d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", dp[M][N] > 0 ? dp[M][N] : 0);
	return 0;
}