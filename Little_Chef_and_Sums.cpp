#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		int mn = INT_MAX, idx = -1, data;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%d", &data);
			if(data < mn){
				mn = data;
				idx = i;
			}
		}
		printf("%d\n", idx);
	}
	return 0;
} 