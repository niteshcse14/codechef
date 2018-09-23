#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first 
#define Y second
const int N = 200005;
struct Line {
    ll m, c, idx;
    Line(ll a , ll b, ll i):
    m(a), c(b), idx(i){}
};
vector<Line> line;
vector<pair<ll, ll> > v[4*N];
ll n, m;
ll pos[N], p[N], s[N],  k[N], c[N];
inline bool comp(Line a, Line b) {
    return a.m > b.m;
} 
ll binary_search(vector<pair<ll, ll> > &v, ll x) {
    ll low = -1, high = v.size() -1;
    while(high - low > 1) {
        ll mid = (low + high)/2;
        if(x <= v[mid].X)
            high = mid;
        else low = mid;
    }
    return line[v[high].Y].m*x + line[v[high].Y].c;
}
inline bool isbad(Line l1, Line l2, Line l3) {
    return (l3.c - l1.c)*(l2.m - l1.m) >= (l2.c - l1.c)*(l3.m - l1.m);
}
void addline(int idx, Line l, int index) {
    if(v[idx].empty()) {   
        v[idx].push_back(mp(LLONG_MAX, index));
        return ;
    }
    while(v[idx].size() > 1 && isbad(line[v[idx][v[idx].size() - 2].Y], line[v[idx][v[idx].size() -1].Y], l) )
        v[idx].pop_back();
    Line l1 = line[v[idx][v[idx].size() - 1].Y];
    ll x = (l.c - l1.c)/(l1.m - l.m);
    v[idx][v[idx].size() - 1].X = x;
    v[idx].push_back(mp(LLONG_MAX, index));
}
void build(int node, int start, int end) {
    if(start == end) {
        addline(node, line[start], start);
        return ;
    }
    int mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);
    v[node] = v[2*node];
    for(int i=0;i<v[2*node + 1].size(); ++i)
        addline(node, line[v[2*node + 1][i].Y], v[2*node + 1][i].Y);
}
ll query(int node, int start, int end, int l, int r, ll x) {
    if(end < start || (end < l || start > r))
        return LLONG_MAX;
    if(start >= l && end <= r)
        return binary_search(v[node], x);
    int mid = (start + end)/2;
    ll p1 = query(2*node, start, mid, l, r, x);
    ll p2 = query(2*node + 1, mid + 1, end, l, r, x);
    return min(p1, p2);
} 
int main() {
    scanf("%lld %lld", &n, &m);
    for(int i=0;i<n;++i) {
        scanf("%lld %lld", &s[i], &p[i]);
        line.push_back(Line(-2*s[i], s[i]*s[i] + p[i], i));
    }
    sort(line.begin(), line.end(), comp);
    for(int i=0;i<n;++i)
        pos[line[i].idx] = i;
 
    vector<ll> d[m];
    for(ll i=0;i<m;++i) {
        scanf("%lld %lld",&c[i], &k[i]);
        for(int j=0;j<k[i];++j) {
            ll x; scanf("%lld", &x); x--;
             d[i].push_back(pos[x]);
        }
        sort(d[i].begin(), d[i].end());
    }
    build(1, 0, n-1);
    for(int i=0;i<m;++i) {
        ll res = LLONG_MAX;
        int prev = 0;
        for(int j=0;j<k[i];++j) {
            res = min(res, query(1, 0, n-1, prev, d[i][j] -1, c[i]));
            prev = d[i][j] + 1;
        }
        res = min(res, query(1, 0, n-1, prev, n-1, c[i]));
        res = res + c[i]*c[i];
        printf("%lld\n", res);
    }
    return 0;
}