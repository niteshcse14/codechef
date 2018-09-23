#include <bits/stdc++.h>
using namespace std;
int t;
string str;
int arr[26];
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        cin >> str;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < str.size(); ++i) {
            arr[str[i] - 97]++;
        }
        bool flag = false;
        for (int i = 0; i < 26; ++i) {
            if(arr[i] > 1) {
                flag = true;
            }
        }
        if(flag) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    return 0;
}
