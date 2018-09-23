#include <bits/stdc++.h>

using namespace std;

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
#define inf (ll)1e17
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

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
ll distance(ll x1, ll y1, ll x2, ll y2)
{
    ll a=x2-x1;a*=a;
    ll b = y2-y1;b*=b;
    a+=b;
    double d = sqrt(a);
    d = ceil(d);
    return (ll) d;
}
int main()
{
    fast;
    ll T,N,M,K,L[15],C[15],X[2001],Y[2001];
    T=sscan();
    while(T--)
    {
    	V_ll v;
    	cin>>N;
    	FOR_Z(i,N)
    	{
    		cin>>X[i]>>Y[i];
    		if(i!=0)
    		{
    			v.pb(distance(X[i],Y[i],X[i-1],Y[i-1]));
    		}
    	}
    	v.pb(distance(X[N-1],Y[N-1],X[0],Y[0]));

    	cin>>M;
    	FOR_Z(i,M)
    	{
    		cin>>L[i]>>C[i];
    	}

    	ll F[N+1]={inf};
    	F[0]=0;
    	FOR_Z(i,N)
    	{
    		FOR_Z(j,M)
    		{
    			if(i-L[j] >= 0)
    			{
    				F[i]=min(F[i-L[j]]+C[j],F[i]);
    			}
    			else
    			{
    				F[i]=min(C[j],F[i]);
    			}
    		}
    	}
    	ll ans=0;
    	FOR_Z(i,N)
    	{
    		ans+=F[i];
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}