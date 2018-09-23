#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
const int INF = (int)1E9;
#define MAXN 100005
#define MAXM 200005
#define LOGN 17
int N, M;
vector<PII> adj[MAXN];
int CC, cycid[MAXN], cychead[MAXN], cycback[MAXN], cycindex[MAXN], mark[MAXN], dep[MAXN], dist[MAXN];
int ea[MAXM], eb[MAXM], ec[MAXM];
VI psum[MAXN];
vector<PII> order, cycs[MAXN];
int cycDist(int a, int b) {
  assert(cycid[a] == cycid[b]);
  if (a == b) return 0;
  int cc = cycid[a], ai = cycindex[a], bi = cycindex[b];
  if (ai > bi) swap(ai, bi);
  return min(psum[cc][bi]- psum[cc][ai], psum[cc][cycs[cc].size()-1] - psum[cc][bi] + psum[cc][ai] + cycback[cc]);
}
void dfs(int x, int p, int w, int d) {
  int sz = adj[x].size();
  order.push_back(PII(x, w));
  dep[x] = d;
  mark[x] = 1;
  REP(i,0,sz) {
    int y = adj[x][i].first;
    if (y == p || mark[y] == 2) continue;
    if (mark[y] == 1) { // cycle
      for(int j=order.size()-1;j>=0;j--) {
        int z = order[j].first;
        cycid[z] = CC;
        if (z == y) break;
        dep[z] = dep[y];
        cycs[CC].push_back(PII(z, order[j].second));
        cycindex[z] = cycs[CC].size() - 1;
      }
      cycs[CC].push_back(PII(y, adj[x][i].second));
      cycback[CC] = adj[x][i].second;
      cycindex[y] = cycs[CC].size() - 1;
      cychead[CC] = y;
 
      CC++;
      continue;
    }
    dfs(y, x, adj[x][i].second, d+1);
  }
  order.pop_back();
  mark[x] = 2;
}
 
int par[MAXN];
void dfslen(int x, int d, int depth) {
  dist[x] = d;
  dep[x] = depth;
  int sz = adj[x].size();
  REP(i,0,sz) {
    int y = adj[x][i].first, w = adj[x][i].second;
    par[y] = x;
    dfslen(y, d + w, depth + 1);
  }
}
 
int RT, dpar[LOGN + 1][MAXN];
void initLogTreepar() {
  par[RT] = RT;
  REP(i, 0, CC) dpar[0][i] = par[i];
  REP(j, 1, LOGN + 1) {
    REP(i, 0, CC) {
      dpar[j][i] = dpar[j - 1][dpar[j - 1][i]];
    }
  }
}
int getDistUp(int a, int d) {
  for (int j = LOGN; j >= 0; j--) {
    if (d & (1<<j)) a = dpar[j][a];
  }
  return a;
}
int lca(int a, int b) {
  int d = 0, mind = min(dep[a], dep[b]);
  if (a == b) return a;
  for (int j = LOGN; j >= 0; j--) {
    int nd = d + (1 << j);
    if (nd > mind) continue;
    if (getDistUp(a, dep[a] - nd) == getDistUp(b, dep[b] - nd)) d = nd;
  }
  return getDistUp(a, dep[a] - d);
}
int getChild(int a, int b){
  return getDistUp(a, dep[a] - (dep[b] + 1));
}
map<int,int> dirNode[MAXN];
 
int main() {
  //freopen("input", "r", stdin);
  cin >> N >> M;
  REP(i,0,M) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(PII(b,c));
    adj[b].push_back(PII(a,c));
    ea[i] = a; eb[i] = b; ec[i] = c;
  }
  FILL(cycindex, -1);
  dfs(1, -1, -1, 0);
  REP(i,1,N+1) {
    if (cycindex[i] == -1) {
      cycid[i] = CC;
      cychead[CC] = i;
      cycs[CC].push_back(PII(i,-1));
      CC++;
    }
  }
 
  REP(i,0,CC) {
    int sum = 0;
    psum[i].push_back(0);
    REP(j,1,cycs[i].size()) {
      sum += cycs[i][j-1].second;
      psum[i].push_back(sum);
    }
    /*
    cerr << "head:" << cychead[i] << endl;
    REP(j,0,cycs[i].size()) {
      fprintf(stderr, "%d-(%d/%d)-", cycs[i][j].first, cycs[i][j].second, psum[i][j]);
    }
    cerr << endl;
     */
  }
  REP(i,0,N+1) adj[i].clear();
  REP(i,0,M) {
    int a = ea[i], b = eb[i], w = ec[i];
    int ca = cycid[a], cb = cycid[b];
    if (ca == cb) continue;
    if (dep[a] > dep[b]) {
      swap(a, b);
      swap(ca, cb);
    }
    int hd = cycDist(a, cychead[ca]);
    dirNode[ca][cb] = a;
    adj[ca].push_back(PII(cb, hd + w));
  }
 
  RT = cycid[1];
  dfslen(RT, 0, 0);
  initLogTreepar();
 
  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int ca = cycid[a], cb = cycid[b], ans;
    if (ca == cb) {
      ans = cycDist(a, b);
    } else {
      int cc = lca(ca, cb);
      if (cc == ca || cc == cb) {
        if (cc == cb) {
          swap(ca, cb);
          swap(a, b);
        }
        int child = getChild(cb, ca);
        ans = dist[cb] - dist[ca];
        ans += cycDist(cychead[cb], b);
        ans -= cycDist(cychead[ca], dirNode[ca][child]);
        ans += cycDist(a, dirNode[ca][child]);
      } else {
        int childa = getChild(ca, cc);
        int childb = getChild(cb, cc);
        ans = dist[ca] + dist[cb] - 2 * dist[cc];
        ans += cycDist(cychead[ca], a);
        ans += cycDist(cychead[cb], b);
        ans -= cycDist(cychead[cc], dirNode[cc][childa]);
        ans -= cycDist(cychead[cc], dirNode[cc][childb]);
        ans += cycDist(dirNode[cc][childa], dirNode[cc][childb]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}