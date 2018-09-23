#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
const ll maxn = 1e5 + 5;
ll BITree[maxn];
ll arr[maxn];
ll ans[maxn];
struct queries{
    ll type;
    ll l;
    ll r;
};
queries qu[maxn];
ll tree[3 * maxn];
ll Request_Update[3 * maxn];
void Build_Seg(ll ss, ll se, ll si){
    if(ss == se){
        tree[si] = 1;
        return;
    }
    ll mid = (ss + se) >> 1;
    Build_Seg(ss, mid, 2 * si + 1);
    Build_Seg(mid + 1, se, 2 * si + 2);
    tree[si] = (tree[2 * si + 1] + tree[2 * si + 2]) % MOD;
}
void Update_Elements(ll ss, ll se, ll si, ll qs, ll qe, ll val){
    if(Request_Update[si] != 0){
        tree[si] = (tree[si] + (((se - ss + 1) * Request_Update[si]) % MOD)) % MOD;
        if(ss != se){
            Request_Update[2 * si + 1] = (Request_Update[2 * si + 1] + Request_Update[si]) % MOD;
            Request_Update[2 * si + 2] = (Request_Update[2 * si + 2] + Request_Update[si]) % MOD;
        }
        Request_Update[si] = 0;
    }
    if(qe < ss || se < qs){
        return;
    }
    if(qs <= ss && se <= qe){
        tree[si] = (tree[si] + (((se - ss + 1) * val) % MOD)) % MOD;
        if(ss != se){
            Request_Update[2 * si + 1] = (Request_Update[2 * si + 1] + val) % MOD;
            Request_Update[2 * si + 2] = (Request_Update[2 * si + 2] + val) % MOD;
        }
        return;
    }
    ll mid = (ss + se) >> 1;
    Update_Elements(ss, mid, 2 * si + 1, qs, qe, val);
    Update_Elements(mid + 1, se, 2 * si + 2, qs, qe, val);
    tree[si] = (tree[2 * si + 1] + tree[2 * si + 2]) % MOD;
}
ll getSum_Util(ll ss, ll se, ll si, ll qs, ll qe){
    if(Request_Update[si] != 0){
        tree[si] = (tree[si] + (((se - ss + 1) * Request_Update[si]) % MOD)) % MOD;
        if(ss != se){
            Request_Update[2 * si + 1] = (Request_Update[2 * si + 1] + Request_Update[si]) % MOD;
            Request_Update[2 * si + 2] = (Request_Update[2 * si + 2] + Request_Update[si]) % MOD;
        }
        Request_Update[si] = 0;
    }
    if(qe < ss || se < qs){
        return 0;
    }
    if(qs <= ss && se <= qe){
        return (tree[si] % MOD);
    }
    ll mid = (ss + se) >> 1;
    return ((getSum_Util(ss, mid, 2 * si + 1, qs, qe) + getSum_Util(mid + 1, se, 2 * si + 2, qs, qe)) % MOD);
}
int main()
{
    ll t, n, l, r, type, m;
    //freopen("input.txt", "r", stdin);
    scanf("%lld", &t);
    while(t--){
        memset(tree, 0, sizeof(tree));
        memset(ans, 0, sizeof(ans));
        memset(Request_Update, 0, sizeof(Request_Update));
        scanf("%lld%lld", &n, &m);
        for(ll i = 0; i < m; ++i){
            scanf("%lld%lld%lld", &type, &l, &r);
            qu[i].type = type - 1;
            qu[i].l = l - 1;
            qu[i].r = r - 1;
        }
        Build_Seg(0, m - 1, 0);
        for(ll i = m - 1; i >= 0; --i){
            if(qu[i].type){
                ll val = getSum_Util(0, m - 1, 0, i, i);
                Update_Elements(0, m - 1, 0, qu[i].l, qu[i].r, val);
            }
        }
        for(ll i = 0; i < m; ++i){
            if(!qu[i].type){
                ll tt = getSum_Util(0, m - 1, 0, i, i);
                l = qu[i].l;
                r = qu[i].r;
                ans[l] = (ans[l] + tt) % MOD;
                ans[r + 1] = (ans[qu[i].r + 1] - tt + MOD) % MOD;
            }
        }
        printf("%lld ", ans[0] % MOD);
        for(ll i = 1; i < n; ++i){
            ans[i] += ans[i - 1];
            printf("%lld ", ans[i] % MOD);
        }
        printf("\n");
    }  
     return 0;
}    