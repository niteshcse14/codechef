#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
#define st(v) v.fi][v.se
using namespace std;
const int N = 500005, LOG = 20;
int n, q, m, u, v, c, h[N], col[N][3], cnt[N], ans[N][3][LOG];
pair<int, int> par[N][3][LOG];
vector<pair<int, int>> adj[N];
void add_edge(int u, int c)
{
    cnt[u]++;
    if (cnt[u] <= 2)
        col[u][cnt[u]] = c;
}
 
void parent(int u, int t, int p)
{
    if (t == 0)
    {
        ans[u][t][0] = 1;
        par[u][t][0] = make_pair(p, cnt[p] == 1 ? 1 : 0);
    }
    else
    {
        if (cnt[p] >= 3)
        {
            ans[u][t][0] = 1;
            par[u][t][0] = make_pair(p, 0);
        }
        else if (cnt[p] == 2)
        {
            ans[u][t][0] = 1;
            if (col[p][1] != col[u][t] && col[p][2] != col[u][t])
                par[u][t][0] = make_pair(p, 0);
            else
                par[u][t][0] = make_pair(p, col[p][1] == col[u][t] ? 2 : 1);
        }
        else
        {
            ans[u][t][0] = (col[u][t] != col[p][1]);
            par[u][t][0] = make_pair(p, 1);
        }
    }
    for (int i = 1; (1 << i) <= h[u]; i++)
    {
        ans[u][t][i] = ans[u][t][i - 1] + ans[st(par[u][t][i - 1])][i - 1];
        par[u][t][i] = par[st(par[u][t][i - 1])][i - 1];
    }
}

void DFS(int u, int p = 0) {
    h[u] = h[p] + 1;
    for (pair<int, int> &v : adj[u])
        if (v.fi != p)
            add_edge(v.fi, v.se);
    if (u == 1)
        cnt[u] = 1;
    if (cnt[u] == 1)
        parent(u, 1, p);
    else if (cnt[u] == 2)
        for (int i = 0; i <= 2; i++)
            parent(u, i, p);
    else
        parent(u, 0, p);
    for (pair<int, int> &v : adj[u])
        if (v.fi != p && h[v.fi] == 0)
            DFS(v.fi, u);
}

int LCA(pair<int, int> u, pair<int, int> v) {
    int ret = 0;
    if (u.fi == v.fi)
        return 0;
    if (h[u.fi] < h[v.fi])
        swap(u, v);
    if (h[u.fi] > h[v.fi]){
        for (int i = LOG - 1; i >= 0; i--)
            if ((h[u.fi] - h[v.fi] - 1) >> i & 1)
            {
                ret += ans[st(u)][i];
                u = par[st(u)][i];
            }
        if (par[st(u)][0].fi == v.fi)
            return ret;
        ret += ans[st(u)][0];
        u = par[st(u)][0];
    }
    for (int i = LOG - 1; i >= 0; i--)
        if (par[st(u)][i].fi != par[st(v)][i].fi)
        {
            ret += ans[st(u)][i] + ans[st(v)][i];
            u = par[st(u)][i];
            v = par[st(v)][i];
        }
    if (u.se == 0 || v.se == 0 || col[u.fi][u.se] != col[v.fi][v.se])
        ret++;
    return ret;
}
int main() {
    h[0] = -1;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    DFS(1);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", LCA(make_pair(u, cnt[u] == 1 ? 1 : 0), make_pair(v, cnt[v] == 1 ? 1 : 0)));
    }
}