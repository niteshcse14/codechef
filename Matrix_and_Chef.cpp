#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int arr[MAXN][MAXN], ans[MAXN];
int N, Q, p, val;
void update_mat(){
	for(int i = 1; i < N; ++i){
		ans[i] = -1 * arr[0][i];
	}
	for(int i = 1; i < N; ++i){
		for(int j = i + 1; j < N; ++j){
			if(abs(ans[j] - ans[i]) != arr[i][j]){
				ans[j] = -1 * ans[j];
			}
		}
	}
}
void print_ans(){
	for(int i = 0; i < N; ++i){
		printf("%d ", ans[i]);
	}
	printf("\n");
}
int main(){
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			scanf("%d", &arr[i][j]);
		}
	}
	update_mat();
	print_ans();
	while(Q--){
		scanf("%d", &p);
		p--;
		for(int i = 0; i < N; ++i){
			scanf("%d", &val);
			arr[i][p] = arr[p][i] = val;
		}
		update_mat();
		print_ans();
	}
	return 0;
}