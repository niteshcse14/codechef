#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string str;
ll t, n, one, two, three, four, five;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld", &n);
		one = two = three = four = five = 0;
		for (ll i = 0; i < n; ++i) {
			cin >> str;
			if (str == "cakewalk") {
				one++;
			}
			else if (str == "simple") {
				two++;
			}
			else if (str == "easy") {
				three++;
			}
			else if (str == "easy-medium" || str == "medium") {
				four++;
			}
			else if (str =="medium-hard" || str == "hard") {
				five++;
			}
		}
		if (one && two && three && four && five) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}