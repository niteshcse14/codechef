#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long int
#define fori(i,a,b) for(int i=a;i<b;++i)
#define sfl(a) scanf("%lld",&a)
#define sfllll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
ll t,n,q,idx;
ll ans[maxn];
struct quad{
	ll a,b,c,d;
	quad(){a=0,b=0,c=0,d=0;};
	quad(ll p,ll q,ll r,ll s):
		a(p),b(q),c(r),d(s){};
};
vector<quad>p;
ll val(ll i,ll x){
	return (ll)(p[i].a+(p[i].b*1LL*x)+(p[i].c*1LL*x*x)+(p[i].d*1LL*x*x*x));
}
void solve(ll l, ll r){
	ll low=LLONG_MAX;
	ll high=LLONG_MAX;
	ll mid=(l+r)>>1;
	fori(i,0,n){
		if(val(i,l)<low){
			low=val(i,l);
			ans[l]=i;
		}
		if(val(i,r)<high){
			high=val(i,r);
			ans[r]=i;
		}
	}
	if(ans[l]==ans[r]){
		fori(i,l+1,r)
			ans[i]=ans[l];
	}
	else {
		solve(l,mid);
		solve(mid+1,r);
	}
}
ll a,b,c,d;
int main(){
	sfl(t);
	while(t--){
		p.clear();
		sfl(n);
		fori(i,0,n){
			sfllll(a,b,c,d);
			p.push_back({a,b,c,d});
		}
		solve(0,100000);
		fori(i,0,300)
			fori(j,0,n)
				if(val(j,i)<val(ans[i],i))
					ans[i]=j;
		sfl(q);
		while(q--){
			sfl(idx);
			printf("%lld\n",val(ans[idx],idx));
		}
	}
	return 0;
} 