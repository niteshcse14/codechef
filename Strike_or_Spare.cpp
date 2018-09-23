#include <bits/stdc++.h>
using namespace std;
int t,n;
string den, num;
int main() {
	scanf ("%d", &t);
	while (t--) {
		den = num = "";
		scanf ("%d", &n);
		den = '1';
		for (int i = 0; i < n / 2; ++i) 
			den += '0';
		cout << "1" << " " << den << "\n";
	}
	return 0;
}