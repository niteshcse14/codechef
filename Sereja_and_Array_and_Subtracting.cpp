#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define	mp make_pair
#define	pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ll modpow(ll a, ll b)
{
	ll r = 1;

	while (b) {
		if (b & 1) {
			r = (r * a) % mod;
		}

		a = (a * a) % mod;

		b >>= 1;
	}

	return r;
}

ll modinverse(ll a) 
{
	return modpow(a, mod - 2);
}

inline long long int sscan()
{
   long long int n=0;
   int ch=gc();
   while( ch < '0' || ch > '9' )
        ch=gc();
   while(  ch >= '0' && ch <= '9' )
   {
       n = (n<<3)+(n<<1) + ch-'0';
       ch=gc();
   }
   return n;
}
 
inline void print(long int a)
{
	int i=0;
	char S[20];
	while(a>0)
	{
    	S[i++]=a%10+'0';
		a=a/10;
	}
	--i;
	while(i>=0)
		pc(S[i--]);
	pc('\n');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T=sscan();
    while(T--)
    {
    	ll N=sscan(),a,sum=0;
    	vector<ll> v;
    	FOR_Z(i,N)
    	{
    		a=sscan();
    		v.pb(a);
    	}
    	ll ans=v[0];
    	for(int i=1;i<N;i++)
    	{
    		//printf("gcd %lld\n",gcd(ans,v[i]));
    		ans=gcd(ans,v[i]);
    		//printf("%lld\n",ans);
    	}
    	printf("%lld\n",N*ans);
    }
    return 0;
}