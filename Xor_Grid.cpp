#include <bits/stdc++.h>
using namespace std;
int G[1000][1000];
int main(){
	for(int i = 1; i <= 10; ++i){
		for(int j = 1; j <= 10; ++j){
			if(i == 1 || j == 1){
				G[i][j] = 1;
			}
			else{
				G[i][j] = G[i - 1][j] ^ G[i][j - 1];
			}
			printf("%2d", G[i][j]);
		}
		printf("\n");
	}
	return 0;
}