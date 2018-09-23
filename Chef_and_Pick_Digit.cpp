#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int t;
string str;
int main(){
	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while(t--){
		cin >> str;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < str.length(); ++i){
			cnt[str[i] - 48]++;
		}
		for(int i = 6; i <= 9; ++i){
			for(int j = 0; j < 10; ++j){
				if((i * 10 + j) > 90){
					break;
				}
				if(i == j){
					if(cnt[i] > 1){
						printf("%c", char(10 * i + i));
					}
					else if(cnt[j] > 1){
						printf("%c", char(10 * j + j));
					}
				}
				else if((i * 10 + j) >= 65 && cnt[i] > 0 && cnt[j] > 0){
					printf("%c", char(i * 10 + j));
				}
			}
		}
		printf("\n");
	}
	return 0;
}