#include <bits/stdc++.h>
using namespace std;
// code credit : https://github.com/niklasb/contest-algos/
// blob/master/convex_hull/dynamic.cpp
using line_t = long long;
const line_t is_query = (long long) -2e18;
 
struct Line {
    line_t m, b;
};
 
struct HullDynamic { // will maintain upper hull for maximum
        vector<Line> a;
    int ptr = 0;
        void clear() {
          a.clear();
          ptr = 0;
        }
        bool empty() {
          return a.empty();
        }
        bool bad(int y) {
        auto z = y + 1;
        if (y == 0) {
            if (z == (int) a.size()) return 0;
            return a[y].m == a[z].m && a[y].b <= a[z].b;
        }
        auto x = y - 1;
        if (z == (int) a.size()) return a[y].m == a[x].m && a[y].b <= a[x].b;
        return (double)(a[x].b - a[y].b)*(a[z].m - a[y].m) >= (double)(a[y].b - a[z].b)*(a[y].m - a[x].m);
    }
    void insert_line(line_t m, line_t b) {
            a.push_back({m, b});
        while (a.size() >= 2 && bad((int) a.size() - 2)) a.erase(a.begin() + a.size() - 2);
    }
    line_t query(line_t x) {
            while (ptr < (int) a.size() - 1) {
              Line &me = a[ptr];
              Line &s = a[ptr + 1];
              if (me.b - s.b < (s.m - me.m) * x) {
                ptr++;
              } else {
                break;
              }
            }
        return a[ptr].m * x + a[ptr].b;
    }
}H;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> s(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> p[i];
  }
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int i, int j) { return s[i] < s[j]; });
  vector<long long> c(m);
  vector<vector<int>> at(n);
  for (int i = 0; i < m; i++) {
    int foo;
    cin >> c[i] >> foo;
    while (foo--) {
      int bar;
      cin >> bar;
      bar--;
      at[bar].push_back(i);
    }
  }
  vector<int> idc(m);
  iota(idc.begin(), idc.end(), 0);
  sort(idc.begin(), idc.end(), [&](int i, int j) { return c[i] < c[j]; });
  vector<int> inv_idc(m);
  for (int i = 0; i < m; i++) {
    inv_idc[idc[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    for (int &j : at[i]) {
      j = inv_idc[j];
    }
    sort(at[i].begin(), at[i].end());
  }
  vector<vector<Line>> st(4 * m + 100);
  function<void(int,int,int,int,int,const Line&)> modify = [&](int x, int l, int r, int ll, int rr, const Line &v) {
    if (r < ll || rr < l || rr < ll) {
      return;
    }
    if (ll <= l && r <= rr) {
      st[x].push_back(v);
      return;
    }
    int y = (l + r) >> 1;
    if (ll <= y) {
      modify(x + x, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(x + x + 1, y + 1, r, ll, rr, v);
    }
  };
  for (int i : idx) {
    Line L = {2 * s[i], -p[i] - s[i] * s[i]};
    if (at[i].empty()) {
      modify(1, 0, m - 1, 0, m - 1, L);
    } else {
      modify(1, 0, m - 1, 0, at[i][0] - 1, L);
      modify(1, 0, m - 1, at[i].back() + 1, m - 1, L);
      for (int j = 0; j < (int) at[i].size() - 1; j++) {
        modify(1, 0, m - 1, at[i][j] + 1, at[i][j + 1] - 1, L);
      }
    }
  }
  vector<line_t> res(m, (long long) 9e18);
  function<void(int,int,int)> solve = [&](int x, int l, int r) {
    H.clear();
    for (const Line &li : st[x]) {
      H.insert_line(li.m, li.b);
    }
    if (!H.empty()) {
      for (int i = l; i <= r; i++) {
        res[idc[i]] = min(res[idc[i]], -H.query(c[idc[i]]));
      }
    }
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    solve(x + x, l, y);
    solve(x + x + 1, y + 1, r);
  };
  solve(1, 0, m - 1);
  for (int i = 0; i < m; i++) {
    long long ans = res[i] + c[i] * c[i];
    cout << ans << '\n';
  }
  return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1 << 18;
const int M = 500000;
const long long INF = (long long) 1e18 + 1e9 + 123;

struct Line {
    long long a, b;
    
    Line() {}
    
    Line(long long a, long long b) : a(a), b(b) {}
    
    long long eval(long long x) const {
        return a * 1LL * x + b;
    }
};

long long div_up(long long x, long long y) {
    if (y < 0) {
        x = -x;
        y = -y;
    }
    if (x < 0) {
        return x / y;
    } else {
        return (x + y - 1) / y;
    }
}

long long intersect(const Line &u, const Line &v) {
    return div_up(u.b - v.b, v.a - u.a);
}

struct CHT {
    int ptr;
    vector<long long> points;
    vector<Line> lines;
    
    CHT() {}
    
    CHT(vector<Line> &what) {
        ptr = 0;
        for (Line &l : what) {
            while (!points.empty() && points.back() >= intersect(lines.back(), l)) {
                points.pop_back();
                lines.pop_back();
            }
            if (!lines.empty()) {
                points.push_back(intersect(lines.back(), l));
            }
            lines.push_back(l);
        }
    }
    
    long long get(long long x) {
        if (lines.empty()) {
            return INF;
        }
        while (ptr < (int) points.size() && points[ptr] <= x) {
            ptr++;
        }
        
        return lines[ptr].eval(x);
    }
};

CHT cht[2 * N];
vector<Line> lines[2 * N];

long long get(int i, int tl, int tr, int l, int r, long long x) {
    if (tl >= r || tr <= l) {
        return INF;
    }
    if (l <= tl && tr <= r) {
        return cht[i].get(x);
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * i, tl, tm, l, r, x), get(2 * i + 1, tm, tr, l, r, x));
}
struct Store {
    int x, a, id;
};
struct Customer {
    int x, id;
};
int n, m;
Store store[N];
int to[N];
Customer customer[M];
vector<int> forbidden[M];
long long ans[M];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> store[i].x >> store[i].a;
        store[i].id = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> customer[i].x;
        customer[i].id = i;
        int k;
        cin >> k;
        forbidden[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> forbidden[i][j];
            forbidden[i][j]--;
        }
    }
    sort(store, store + n, [] (const auto &u, const auto &v) {
        return u.x < v.x;
    });
    for (int i = 0; i < n; i++) {
        to[store[i].id] = i;
        lines[N + i].push_back(Line(-2 * store[i].x, store[i].a + store[i].x * 1LL * store[i].x));
    }
    for (int i = N - 1; i >= 1; i--) {
        lines[i].reserve(lines[2 * i].size() + lines[2 * i + 1].size());
        for (const Line &l : lines[2 * i]) {
            lines[i].push_back(l);
        }
        for (const Line &l : lines[2 * i + 1]) {
            lines[i].push_back(l);
        }
    }
    for (int i = 1; i < N + n; i++) {
        cht[i] = CHT(lines[i]);
    }
    
    sort(customer, customer + m, [] (const auto &u, const auto &v) {
        return u.x < v.x;
    });
    for (int i = 0; i < m; i++) {
        vector<int> &our_forbidden = forbidden[customer[i].id];
        for (int &id : our_forbidden) {
            id = to[id];
        }
        our_forbidden.push_back(-1);
        our_forbidden.push_back(n);
        sort(our_forbidden.begin(), our_forbidden.end());
        long long res = INF;
        for (int j = 0; j < (int) our_forbidden.size() - 1; j++) {
            int left = our_forbidden[j] + 1;
            int right = our_forbidden[j + 1];
            res = min(res, get(1, 0, N, left, right, customer[i].x) + customer[i].x * 1LL * customer[i].x);
        }
        ans[customer[i].id] = res;
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
 */