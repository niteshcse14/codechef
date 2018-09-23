#include <bits/stdc++.h>
using namespace std;
int main(){
	int T, N, v1, v2;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d", &N, &v1, &v2);
		double t = sqrt(2) * v1;
		if(v2 < t){
			printf("Stairs\n");
		}
		else{
			printf("Elevator\n");
		}
	}
	return 0;
}