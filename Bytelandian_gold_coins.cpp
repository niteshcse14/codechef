#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
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
ll arr[500001];

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

ll modpowinverse(ll a) 
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

map<ll,ll>ar;
ll coin(ll N)
{
	if(N<12)
	{
		return N;
	}
	else if(N==12)
	{
		return 13;
	}
	if(ar[N])
	{
		return ar[N];
	}
	return ar[N] = max(coin(N/2) + coin(N/3) + coin(N/4),N);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    while(cin>>N)
    {
    	printf("%lld\n",coin(N));
	}
    return 0;
}