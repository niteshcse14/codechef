#include <bits/stdc++.h>
using namespace std;
 
int tc;
int n;
char f[1000005];
map < pair < int , int > , int > m;
 
int main(){
	scanf("%s",&f);
	n = strlen(f);	
	
	long long res = 0;
	int a ,b ,c ;
	a = b = c = 0;
		m[make_pair(0,0)]++;
	for ( int i = 0; i < n; i++ ){
		if ( f[i] == 'A' ) a++;
		if ( f[i] == 'B' ) b++;
		if ( f[i] == 'C' ) c++;
		int ab = a-b;
		int ac = a-c;
		res += m[make_pair(ab,ac)];
		cout << ab << " " << ac << "  " << res << endl;
		m[make_pair(ab,ac)]++;
	}
	
	cout << res << endl;
	return 0;
}