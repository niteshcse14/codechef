#include <bits/stdc++.h>
using namespace std;
int t, n;
int arr[105];
float S;
float sum;
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d ", 1);
        for (int i = 1; i < n; ++i) {
            printf("%d ", 2 * i + 1);
        }
        printf("\n");
    }
    return 0;
}
