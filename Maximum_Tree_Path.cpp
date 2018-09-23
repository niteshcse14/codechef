#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
 
const int MAXN = 100*1000;
const int MAXLIST = MAXN * 2;
const int LOG_MAXLIST = 18;
const int SQRT_MAXLIST = 447;
const int MAXBLOCKS = MAXLIST / ((LOG_MAXLIST+1)/2) + 1;
 
vector<vector<int>> g;
int h[MAXN]; // vertex height
vector<int> a; // dfs list
int a_pos[MAXN]; // positions in dfs list
int block; // block size = 0.5 log A.size()
int bt[MAXBLOCKS][LOG_MAXLIST+1]; // sparse table on blocks (relative minimum positions in blocks)
int bhash[MAXBLOCKS]; // block hashes
int brmq[SQRT_MAXLIST][LOG_MAXLIST/2][LOG_MAXLIST/2]; // rmq inside each block, indexed by block hash
int Log2[2*MAXN]; // precalced logarithms (floored values)
 
// walk graph
void dfs (int v, int curh) {
  h[v] = curh;
  a_pos[v] = (int)a.size();
  a.push_back (v);
  for (size_t i=0; i<g[v].size(); ++i)
    if (h[g[v][i]] == -1) {
      dfs (g[v][i], curh+1);
      a.push_back (v);
    }
}
 
int log (int n) {
  int res = 1;
  while (1<<res < n)  ++res;
  return res;
}
 
// compares two indices in a
inline int min_h (int i, int j) {
  return h[a[i]] < h[a[j]] ? i : j;
}
 
// O(N) preprocessing
void build_lca(int root, int n) {
  memset(h, -1, n * sizeof(h[0]));
  a.clear();
  dfs(root, 0);
  int sz = (int)a.size();
  block = (log(sz) + 1) / 2;
  int blocks = sz / block + (sz % block ? 1 : 0);
 
  // precalc in each block and build sparse table
  memset (bt, 255, sizeof bt);
  for (int i=0, bl=0, j=0; i<sz; ++i, ++j) {
    if (j == block)
      j = 0,  ++bl;
    if (bt[bl][0] == -1 || min_h (i, bt[bl][0]) == i)
      bt[bl][0] = i;
  }
  for (int j=1; j<=log(sz); ++j)
    for (int i=0; i<blocks; ++i) {
      int ni = i + (1<<(j-1));
      if (ni >= blocks)
        bt[i][j] = bt[i][j-1];
      else
        bt[i][j] = min_h (bt[i][j-1], bt[ni][j-1]);
    }
 
  // calc hashes of blocks
  memset (bhash, 0, sizeof bhash);
  for (int i=0, bl=0, j=0; i<sz||j<block; ++i, ++j) {
    if (j == block)
      j = 0,  ++bl;
    if (j > 0 && (i >= sz || min_h (i-1, i) == i-1))
      bhash[bl] += 1<<(j-1);
  }
 
  // precalc RMQ inside each unique block
  memset (brmq, 255, sizeof brmq);
  for (int i=0; i<blocks; ++i) {
    int id = bhash[i];
    if (brmq[id][0][0] != -1)  continue;
    for (int l=0; l<block; ++l) {
      brmq[id][l][l] = l;
      for (int r=l+1; r<block; ++r) {
        brmq[id][l][r] = brmq[id][l][r-1];
        if (i*block+r < sz)
          brmq[id][l][r] =
            min_h (i*block+brmq[id][l][r], i*block+r) - i*block;
      }
    }
  }
 
  // precalc logarithms
  for (int i=0, j=0; i<sz; ++i) {
    if (1<<(j+1) <= i)  ++j;
    Log2[i] = j;
  }
}
 
// answers RMQ in block #bl [l;r] in O(1)
inline int lca_in_block (int bl, int l, int r) {
  return brmq[bhash[bl]][l][r] + bl*block;
}
 
// answers LCA in O(1)
int lca (int v1, int v2) {
  int l = a_pos[v1],  r = a_pos[v2];
  if (l > r)  swap (l, r);
  int bl = l/block,  br = r/block;
  if (bl == br)
    return a[lca_in_block(bl,l%block,r%block)];
  int ans1 = lca_in_block(bl,l%block,block-1);
  int ans2 = lca_in_block(br,0,r%block);
  int ans = min_h (ans1, ans2);
  if (bl < br - 1) {
    int pw2 = Log2[br-bl-1];
    int ans3 = bt[bl+1][pw2];
    int ans4 = bt[br-(1<<pw2)][pw2];
    ans = min_h (ans, min_h (ans3, ans4));
  }
  return a[ans];
}
 
vi p, r;
vector<array<ll, 3>> diam;
ll dep[100001];
const int L = 17;
int lc[100001][L];
int in[100001];
int out[100001];
int TIMER = 0;
 
void dfs(int v, int p, const vector<vii>& g) {
//  cerr << v << ' ' << p << endl;
//  assert(!in[v]);
  in[v] = ++TIMER;
  lc[v][0] = p;
  for (int i = 1; i < L; ++i) lc[v][i] = lc[lc[v][i-1]][i-1];
  for (int i = 0; i < (int)g[v].size(); ++i) {
    int nv = g[v][i].first;
    if (nv == p) continue;
    dep[nv] = dep[v] + g[v][i].second;
    dfs(nv, v, g);
  }
  out[v] = ++TIMER;
}
 
bool ispr(int u, int v) {
  return in[v] <= in[u] && out[v] >= out[u];
}
 
int mlca(int u, int v) {
  if (ispr(u, v)) return v;
  for (int i = L - 1; i >= 0; --i) {
    int nv = lc[v][i];
    if (!ispr(u, nv)) v = nv;
  }
  return lc[v][0];
}
 
ll dist(int u, int v) {
  int x = lca(u, v);
  return dep[u] + dep[v] - 2 * dep[x];
}
 
int getp(int x) {
  if (p[x] == x) return x;
  return p[x] = getp(p[x]);
}
 
ll ans = 0;
void merge(int a, int b, int dd, int mi) {
  int pa = getp(a), pb = getp(b);
//  assert(pa != pb);
  if (r[pa] > r[pb]) {
    swap(a, b);
    swap(pa, pb);
  }
  p[pa] = pb;
  if (r[pa] == r[pb]) ++r[pb];
  array<ll, 3> res = max(diam[pa], diam[pb]);
  if (1) for (int i = 1; i < 3; ++i) for (int j = 1; j < 3; ++j) {
    int u = diam[pa][i], v = diam[pb][j];
    array<ll, 3> cand = {dist(u,v), u, v};
    res = max(res, cand);
  }
  diam[pb] = res;
//  cerr << dd << ' ' << mi << ' ' << res[0] << ' ' << a << ' ' << b << ' ' << pa << ' ' << pb << endl;
  ans = max(ans, dd * (ll)mi * res[0]);
}
 int main() {
    vvi d(10001);
    for (int i = 1; i < (int)d.size(); ++i) 
        for (int j = i; j < (int)d.size(); j += i) 
            d[j].push_back(i);
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test) {
        ans = 0;
        int n;
        scanf("%d", &n);
        vi a(n);
        for (int i = 0; i < n; ++i) 
            scanf("%d", &a[i]);
        vector<vii> adj(n);
        g.assign(n, vi());
        for (int i = 0; i < n-1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            --u; --v;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build_lca(0, n);
        dfs(0, 0, adj);
        //    cerr << "here\n";
        vvi inds(d.size());
        for (int i = 0; i < n; ++i) 
            for (int x : d[a[i]]) 
                inds[x].push_back(i);
        r.assign(n, 0);
        p.resize(n);
        diam.resize(n);
        //for (int i = 0; i < n; ++i) p[i] = i;
        for (int dd = 1; dd < (int)d.size(); ++dd) {
            if (!inds[dd].empty()) {
                //      cerr << dd << endl;
                vii ts;
                for (int x : inds[dd]) {
                    p[x] = x;
                    r[x] = 0;
                    diam[x] = {0, x, x};
                    ts.emplace_back(a[x], x);
                }
                sort(ts.rbegin(), ts.rend());
                int mi = 1e9;
                for (pii p : ts) {
                    int v = p.second;
                    mi = min(mi, p.first);
                    for (int u : g[v]) 
                        if (a[u] % dd == 0 && pii(a[u], u) > pii(a[v], v))
                            merge(v, u, dd, mi);        
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}