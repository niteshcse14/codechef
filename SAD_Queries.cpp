#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
 
const int MAXN = 1000000;
 
 
long long readInt(long long l, long long r, char endd) {
    long long x = 0;
    int cnt = 0;
    int fi = -1;
    bool is_neg = false;
    while (true) {
        char g = getchar();
        if (g == '-') {
            assert(fi == -1);
            is_neg = true;
            continue;
        }
        if ('0' <= g && g <= '9') {
            x *= 10;
            x += g - '0';
            if (cnt == 0) {
                fi = g - '0';
            }
            cnt++;
            assert(fi != 0 || cnt == 1);
            assert(fi != 0 || is_neg == false);
 
            assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
        }
        else if (g == endd) {
            if (is_neg) {
                x = -x;
            }
            assert(l <= x && x <= r);
            return x;
        }
        else {
            assert(false);
        }
    }
}
string readString(int l, int r, char endd) {
    string ret = "";
    int cnt = 0;
    while (true) {
        char g = getchar();
        assert(g != -1);
        if (g == endd) {
            break;
        }
        cnt++;
        ret += g;
    }
    assert(l <= cnt && cnt <= r);
    return ret;
}
long long readIntSp(long long l, long long r) {
    return readInt(l, r, ' ');
}
long long readIntLn(long long l, long long r) {
    return readInt(l, r, '\n');
}
string readStringLn(int l, int r) {
    return readString(l, r, '\n');
}
string readStringSp(int l, int r) {
    return readString(l, r, ' ');
}
 
char A[MAXN + 1];
 
int main()
{
    int tests = readIntLn(1, 40);
    for (assert(1 <= tests && tests <= 40); tests --;) {
        int n;
        long long k;
        //assert(scanf("%d%lld", &n, &k) == 2);
        n = readIntSp(1, 100000);
        k = readIntLn(0, 20000000000LL);
        assert(1 <= n && n <= 100000);
 
        long long base = (n + 2LL) * (n - 1) / 2; // 2 + 3 + .. + n
        if (k < base) {
            puts("-1");
        } else {
            int l = 1, r = n;
            vector<int> a;
            while (l + 2 <= r && base + (r - l - 1) <= k) {
                base += (r - l - 1);
                a.push_back(l ++);
                a.push_back(r --);
            }
            int remain = r - l + 1;
            for (int i = l; i <= r; ++ i) {
                a.push_back(i);
            }
            if (base < k && k < base + remain) {
                int len = k - base;
                for (int i = 0; i < len; ++ i) {
                    a[n - 1 - i] = a[n - 1 - i - 1];
                }
                a[n - 1 - len] = r;
            }
 
            for (int i = 1; i < n; ++ i) {
                k -= max(a[i], a[i - 1]);
            }
            if (k == 0) {
                for (int i = 0; i < n; ++ i) {
                    printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
                }
            } else {
                puts("-1");
            }
        }
    }
    return 0;
}
