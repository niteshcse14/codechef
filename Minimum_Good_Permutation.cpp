#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 3){
			printf("2 3 1\n");
			continue;
		}
		if(n % 2 == 0){
			for(int i = 1; i <= n; i += 2){
				printf("%d %d ", i + 1, i);
			}
			printf("\n");
		}
		else{
			for(int i = 1; i <= n - 2; i += 2){
				printf("%d ", i + 1);
				if(i != n - 2){
					printf("%d ", i);
				}
			}
			printf("%d %d\n", n, n - 2);
		}
	}
}