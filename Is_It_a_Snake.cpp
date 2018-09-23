#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
vector < int > adj1[MAXN];
vector < int > adj2[MAXN];
char str[3][510];
int N, T;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < 2; ++i){
			scanf("%s", str[i]);
		}
		for(int i = 0; i < N; ++i){
			if(str[0][i] == '#'){
				if(str[1][i] == '#'){
					adj1[i].push_back(11);
				}
				if((i + 1) < N && str[0][i + 1] == '#'){
					adj1[i].push_back(i + 1);
				}
				if((i - 1) >= 0 && str[0][i - 1] == '#'){
					adj1[i].push_back(i - 1);
				}
			}
		}
		for(int i = 0; i < N; ++i){
			if(str[1][i] == '#'){
				if(str[0][i] == '#'){
					adj2[i].push_back(10);
				}
				if((i + 1) < N && str[1][i + 1] == '#'){
					adj2[i].push_back(i + 1);
				}
				if((i - 1) >= 0 && str[1][i - 1] == '#'){
					adj2[i].push_back(i - 1);
				}
			}
		}
		bool flag = true;
		int num_first = 0, num_zero = 0, next_pos = 0, next_pos_num = 0;
		for(int i = 0; i < N - 1; ++i){
			if(adj1[i].size() > 0){
				if(adj1[i + 1].size() == 0 && adj2[i].size() == 0){
					next_pos = 1;
				}
			}
			if(next_pos == 1 && (adj1[i].size() > 0 || adj2[i].size() > 0)){
				flag = false;
			}
		}
		for(int i = 0; i < N; ++i){
			if(adj1[i].size() > 2 && adj2[i].size() > 2){
				flag = false;
				break;
			}
			if(adj1[i].size() > 0 || adj2[i].size() > 1){
				num_first = 1;
			}
			if(adj1[i].size() == 0 && adj2[i].size() == 0 && num_first == 1){
				num_zero = 1;
			}
			if((adj1[i].size() > 0 || adj2[i].size() > 1) && num_zero == 1){
				flag = false;
				break;
			}
		}
		if(flag){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}