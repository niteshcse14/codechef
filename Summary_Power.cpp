#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int t,n,temp,k;
string str;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		cin >> str;
		long long res=0;
		for(int i=1;i<n;++i){
			if(str[i]!=str[i-1]){
				int a = max (0, i - k);
				int b = min(i,n - k);
				res+= b - a;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}