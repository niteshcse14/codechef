#include <bits/stdc++.h>
using namespace std;
char str[111111];
int main(){
	int t, n, k, cnt, ans, ans1;
	char ch;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %s", &n, &k, str);
		ch = str[0];
		cnt = 0;
		ans = 0;
		if(k == 1){
			int a1 = 0, a2 = 0;
            for (int i = 0; i < n; i++) {
                (str[i] - '0' == (i&1) ? a1 : a2)++;
            }
            if (a1 < a2) {
                printf("%d\n", a1);
                for (int i = 1; i <= n; i++) {
                    printf("%d", i&1);
                }
                printf("\n");
            } else {
                printf("%d\n", a2);
                for (int i = 0; i < n; i++) {
                    printf("%d", i&1);
                }
                printf("\n");
            }
			continue;
		}
		ch = str[0];
		cnt = 0;
		ans = 0;
		for(int i = 0; i <= n; ++i){
			if(ch == str[i]){
				cnt++;
			}
			else{
				ans += cnt / (k + 1);
				for(int j = i - cnt + k - !(cnt % (k + 1)); j < i; j += k + 1){
					str[j] ^= 1;
				}
				ch = str[i];
				cnt = 1;
			}
		}
		cout << ans << "\n" << str << "\n";
	}
	return 0;
}