#include <bits/stdc++.h>
using namespace std;
int size = 0;
int M, type, L, R, k, x;
int main()
{
	scanf("%d", &M);
	while(M--){
		scanf("%d", &type);
		if(type == 0){
			scanf("%d", &x);
			arr[size++] = x;
		}
		else if(type == 1){
			scanf("%d %d %d", &L, &R, &x);
		}
		else if(type == 2){
			scanf("%d", &x);
		}
		else if(type == 3){
			scanf("%d %d %d", &L, &R, &x);
		}
		else if(type == 4){
			scanf("%d %d %d", &L, &R, &k);
		}
	}
	return 0;
}