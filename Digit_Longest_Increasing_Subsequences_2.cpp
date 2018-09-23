#include <bits/stdc++.h>
using namespace std;
const int mod= 1e9 + 7;
#define pii pair<int,int>
#define mp make_pair
 
void solve (){
	int n;
	cin>>n;
	vector <int> v;
	int x;
	for (int i=1; i<=n; i++) {
		cin>>x;
		v.push_back(x);
	}
	for (int i=0; i<v.size(); i++) cout<<v[i];
	cout<<endl;	
 
}
 
int main(){
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
} 