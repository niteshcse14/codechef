#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int t;
bool check;
string first_str, second_str;
int main() {
	scanf("%d", &t);
	while (t--) {
		check = false;
		cin >> first_str >> second_str;
		if (first_str[0] == 'b' && first_str[2] == 'b' && first_str[1] == 'o')
			check = true;
		if (second_str[0] == 'b' && second_str[2] == 'b' && second_str[1] == 'o')
			check = true;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (i == j) continue;
				for (int k = 0; k < 3; ++k) {
					if (j == k || i == k) continue;
					if (first_str[i] == 'b' || second_str[i] == 'b') {
						if (first_str[j] == 'o' || second_str[j] == 'o') {
							if (first_str[k] == 'b' || second_str[k] == 'b') {
								check = true;
							}
						}
					}
				}
			}
		}
		if (check) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}