#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
 
int power(int a,int b,int m = MOD){
    if(b == 0) return 1;
    if(b == 1) return a;
    int x = power(a,b/2,m)%m;
    x = (x*x)%m;
    if(b%2) return (x*a)%m;
    return x;
}
 
int n,q,bls = 200;
vi fac[100005];
int a[50005];
int cnt[1005][100005];
 
int solve(int l,int r,int cur){
    int res = 0;
    while(l <= r){
        if(l%bls == 0 and r-l+1 >= bls){
            res += cnt[l/bls][cur];
            l += bls;
        }
        else{
            if(a[l]%cur == 0) res++;
            l ++;
        }
    }
    return res;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    FOR(i,1,100001){
        for(int j = i; j <= 100000; j += i) fac[j].pb(i);
    }
 
    cin >> n;
    REP(i,n){
        cin >> a[i];
        for(auto x:fac[a[i]]) cnt[i/bls][x] ++;
    }
 
    cin >> q;
    WL(q){
        int type; cin >> type;
        if(type == 1){
            int x,y; cin >> x >> y;
            x --;
            for(auto lol:fac[a[x]]) cnt[x/bls][lol] --;
            a[x] = y;
            for(auto lol:fac[a[x]]) cnt[x/bls][lol] ++;
        }
        else{
            int l,r,g; cin >> l >> r >> g;
            l --; r --;
            vi pf;
            for(int i = 2; i*i <= g; i ++){
                if(g%i == 0) pf.pb(i);
                while(g%i == 0) g /= i;
            }
            if(g > 1) pf.pb(g);
            int ans = 0;
            REP(i,(1<<pf.size())){
                int cur = 1,tot = 0;
                REP(j,pf.size()){
                    if((1<<j)&i) cur *= pf[j],tot ++;
                }
                if(tot%2 == 0){
                    ans += solve(l,r,cur);
                }
                else{
                    ans -= solve(l,r,cur);
                }
            }
            cout << ans << endl;
        }
    }
}